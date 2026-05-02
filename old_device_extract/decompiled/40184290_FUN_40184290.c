// Function : FUN_40184290
// Address  : 0x40184290
// Size     : 85 bytes


bool FUN_40184290(byte param_1)

{
  if (param_1 == 0x17) {
    return true;
  }
  if (param_1 < 0x18) {
    if (param_1 == 9) {
      return true;
    }
    if (param_1 < 10) {
      if (6 < (byte)(param_1 - 1)) {
        return false;
      }
    }
    else if (3 < (byte)(param_1 - 0xe)) {
      return false;
    }
  }
  else {
    if (param_1 < 0xca) {
      if (199 < param_1) {
        return true;
      }
      return param_1 == 0x31;
    }
    if (4 < (byte)(param_1 + 0x35)) {
      return false;
    }
  }
  return true;
}

