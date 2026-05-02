// Function : FUN_40123950
// Address  : 0x40123950
// Size     : 66 bytes


void FUN_40123950(byte param_1)

{
  if (param_1 != 0xf) {
    if (param_1 < 0x10) {
      if ((param_1 != 2) && ((param_1 < 2 || (1 < (byte)(param_1 - 6))))) goto LAB_4012398e;
    }
    else if ((param_1 != 0x31) && ((param_1 < 0x31 || (3 < (byte)(param_1 + 0x36)))))
    goto LAB_4012398e;
  }
  FUN_40123ccc();
  FUN_40104628();
  FUN_401049a0(0x3ffc7ef0);
LAB_4012398e:
  FUN_401850b4();
  return;
}

