package tilemusicgame.tutorial.rafagan.tilemusicgame

import android.os.Bundle
import org.anddev.andengine.engine.Engine
import org.anddev.andengine.engine.camera.Camera
import org.anddev.andengine.engine.options.EngineOptions
import org.anddev.andengine.engine.options.resolutionpolicy.RatioResolutionPolicy
import org.anddev.andengine.entity.primitive.Rectangle
import org.anddev.andengine.entity.scene.Scene
import org.anddev.andengine.entity.scene.background.BaseBackground
import org.anddev.andengine.entity.scene.background.ColorBackground
import org.anddev.andengine.entity.scene.background.IBackground
import org.anddev.andengine.opengl.font.Font
import org.anddev.andengine.opengl.font.FontFactory
import org.anddev.andengine.ui.activity.BaseGameActivity

class MainActivity : BaseGameActivity() {
    lateinit var rect: Rectangle

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

    override fun onLoadResources() {

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
