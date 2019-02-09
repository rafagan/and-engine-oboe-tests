package tilemusicgame.tutorial.rafagan.tilemusicgame

import android.graphics.Paint
import org.anddev.andengine.engine.Engine
import org.anddev.andengine.engine.camera.Camera
import org.anddev.andengine.engine.options.EngineOptions
import org.anddev.andengine.engine.options.resolutionpolicy.RatioResolutionPolicy
import org.anddev.andengine.entity.primitive.Rectangle
import org.anddev.andengine.entity.scene.Scene
import org.anddev.andengine.entity.scene.background.ColorBackground
import org.anddev.andengine.ui.activity.BaseGameActivity
import android.media.MediaPlayer
import android.util.Log
import android.content.pm.PackageManager
import android.os.Build


class MainActivity : BaseGameActivity() {
    companion object {
        init {
            // Used to load the 'native-lib' library on application startup.
            System.loadLibrary("native-lib")
        }
    }

    lateinit var rect: Rectangle
    var sound = MediaPlayer()

    override fun onLoadEngine(): Engine {
        val camera = Camera(0F, 0F, 480F, 800F)
        val engineOptions = EngineOptions(
            true,
            EngineOptions.ScreenOrientation.PORTRAIT,
            RatioResolutionPolicy(480F, 800F),
            camera
        )

        return Engine(engineOptions)
    }

    fun playRawFileSound() {
        sound = MediaPlayer.create(this, R.raw.whistle)
        sound.isLooping = true
        sound.start()

        Paint()
    }

    fun playAssetFileSound() {
        val descriptor = assets.openFd("world_clear.ogg")
        sound.setDataSource(descriptor.fileDescriptor, descriptor.startOffset, descriptor.length)
        descriptor.close()

        sound.prepare()
        sound.setVolume(1f, 1f)
        sound.isLooping = true
        sound.start()
    }

    fun checkDeviceAudioCapabilities() {
        /*
            android.hardware.audio.low_latency indicates a continuous output latency of 45 ms or less.
            android.hardware.audio.pro indicates a continuous round-trip latency of 20 ms or less.
         */
        val hasLowLatencyFeature = packageManager.hasSystemFeature(PackageManager.FEATURE_AUDIO_LOW_LATENCY)
        Log.d("Audio latencia", hasLowLatencyFeature.toString())
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            val hasProFeature = packageManager.hasSystemFeature(PackageManager.FEATURE_AUDIO_PRO)
            Log.d("Audio pro", hasProFeature.toString())
        }
    }

    override fun onLoadResources() {
        Log.d("testando 123", stringFromJNI(this))
//        playSound(assets)

        checkDeviceAudioCapabilities()
    }

    fun callFromJava() {
        Log.d("JNI_CAll", "Chamei o Java do C++")
    }

    override fun onLoadScene(): Scene {
        val scene = Scene()
        scene.background = ColorBackground(1F, 1F, 0F)

        rect = Rectangle(100F, 100F, 100F, 200F)
        rect.setColor(1F, 0F, 0F, 0.5F)
        scene.attachChild(rect)

        return scene
    }

    override fun onLoadComplete() {

    }
}
