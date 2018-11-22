package tilemusicgame.tutorial.rafagan.tilemusicgame

import android.content.res.AssetManager


/**
 * A native method that is implemented by the 'native-lib' native library,
 * which is packaged with this application.
 */
external fun stringFromJNI(): String

external fun playSound(assetManager: AssetManager)