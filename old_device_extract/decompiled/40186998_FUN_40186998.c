// Function : FUN_40186998
// Address  : 0x40186998
// Size     : 52 bytes


byte FUN_40186998(byte *param_1)

{
  byte bVar1;
  
  bVar1 = 0x11;
  if (((*param_1 & 0xc) != 0) && (bVar1 = 0x10, (*param_1 & 0x8c) == 0x88)) {
    if ((param_1[1] & 3) == 3) {
      bVar1 = param_1[0x1e];
    }
    else {
      bVar1 = param_1[0x18];
    }
    bVar1 = bVar1 & 0xf;
  }
  return bVar1;
}

