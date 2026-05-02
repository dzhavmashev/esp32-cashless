// Function : FUN_40186c44
// Address  : 0x40186c44
// Size     : 38 bytes


int FUN_40186c44(int param_1,undefined1 param_2)

{
  if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
    *(undefined1 *)(param_1 + 0x11) = param_2;
    memw();
  }
  memw();
  return param_1 + 0x12;
}

