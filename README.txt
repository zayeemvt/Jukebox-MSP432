API Design Goals:
================================================================================
[X] Goal 1: Port/Improve all APIs to a general-purpose student starter project
    [X] LEDs
    [X] Graphics Overlay
        -- Since the API which I ended up using the most is the Graphics API, I
           specifically decoupled this from the big API struct.
    [X] Basic Software Timers
        -- If we restrict students to never touch TIMER32_0 directly, we can 
           reduce most of the complexity of hardware timers. In fact, we would
           only need a single global variable for rollovers - see the code for
           more details.
    [X] Buttons
        -- To maintain consistent behavior when [Button_isPressed()] or when
           [Button_isTapped()] are called, I chose to give the Button its own
           refresh function. Thus, state changes only occur when the super-loop
           polls another round of execution. This removes a possible confusion
           point where calling [Button_isPressed()] at different points may
           potentially exhibit different behavior.
    [X] PWM with the Buzzer

Project Overview:
================================================================================
    
           
    Buzzer (API Modules: PWM with Buzzer, Buttons)
        -- This demo provides the capability to play arbitrary notes from the
           board every second.Tap Launchpad S1/S2 to change the 
           note name (C, D, E, F, etc.), and tap Boosterpack S1/S2
           to change the note's octave.Tap the joystick push button to pause/unpause.
    
 