// Function : FUN_40186900
// Address  : 0x40186900
// Size     : 70 bytes


undefined4 FUN_40186900(int param_1,int param_2,byte param_3)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = param_1;
  while (iVar2 - param_1 < (int)(uint)*(byte *)(param_1 + 1)) {
    pbVar1 = (byte *)(iVar2 + 2);
    iVar2 = iVar2 + 1;
    if (((param_3 ^ *pbVar1) & 0x7f) == 0) {
      return 1;
    }
  }
  if (param_2 != 0) {
    iVar2 = param_2;
    do {
      if ((int)(uint)*(byte *)(param_2 + 1) <= iVar2 - param_2) {
        return 0;
      }
      pbVar1 = (byte *)(iVar2 + 2);
      iVar2 = iVar2 + 1;
    } while (((param_3 ^ *pbVar1) & 0x7f) != 0);
    return 1;
  }
  return 0;
}

