package tilemusicgame.tutorial.rafagan.tilemusicgame

import android.app.Activity
import android.content.res.AssetManager


/**
 * A native method that is implemented by the 'native-lib' native library,
 * which is packaged with this application.
 */
external fun stringFromJNI(activity: Activity): String

external fun playSound(assetManager: AssetManager)