// Function : FUN_400e08b0
// Address  : 0x400e08b0
// Size     : 73 bytes


bool FUN_400e08b0(uint *param_1)

{
  bool bVar1;
  byte bVar2;
  
  bVar1 = false;
  if (param_1 != (uint *)0x0) {
    bVar2 = (byte)param_1[2] & 0x7f;
    if (bVar2 == 8) {
      bVar1 = true;
      if ((param_1[1] != 0) || ((int)*param_1 < 0)) {
        bVar1 = false;
      }
    }
    else if (bVar2 == 10) {
      bVar1 = (uint)(*param_1 + 0x80000000 < *param_1) + param_1[1] == 0;
    }
  }
  return bVar1;
}

