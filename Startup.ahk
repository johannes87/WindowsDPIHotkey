SetDPI(dpiValue)
{
    EnvGet, userProfile, USERPROFILE
    workDir = %userProfile%\bin
    Run SetDPI.exe %dpiValue%, %workDir%, Hide
}


!^j::
SetDPI(100)
return

!^k::
SetDPI(175)
return

!^l::
SetDPI(200)
return
