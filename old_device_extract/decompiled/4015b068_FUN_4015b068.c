// Function : FUN_4015b068
// Address  : 0x4015b068
// Size     : 77 bytes


int FUN_4015b068(uint param_1,uint param_2)

{
  if ((param_2 & 0x80) == 0) {
    if (param_1 == 0x9b4) {
      return 0xe;
    }
    if (0x9b3 < param_1) {
      return -1;
    }
  }
  else {
    if (param_1 == 0x9b4) {
      return 0xe;
    }
    if (0x9b3 < param_1) {
      return (param_1 - 0x9d0) / 0x14 + 0xf;
    }
  }
  return (int)(param_1 - 0x967) / 5;
}

