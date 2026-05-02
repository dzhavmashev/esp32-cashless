// Function : FUN_400d4db0
// Address  : 0x400d4db0
// Size     : 81 bytes


int FUN_400d4db0(uint *param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = (byte)param_1[2];
  if ((bVar1 & 0x7f) == 0) {
    *(byte *)(param_1 + 2) = bVar1 & 0x80 | 0x20;
    *param_1 = bVar1 & 0x7f;
    param_1[1] = bVar1 & 0x7f;
  }
  iVar2 = 0;
  if (((((param_1[2] & 0x20) != 0) && (iVar2 = 0, param_2 != 0)) &&
      (iVar2 = FUN_400d3edc(param_1), iVar2 == 0)) &&
     (iVar2 = FUN_40183ab0(param_1,param_3), iVar2 != 0)) {
    *(int *)(iVar2 + 0xc) = param_2;
    *(byte *)(iVar2 + 8) = *(byte *)(iVar2 + 8) & 0x7f;
  }
  return iVar2;
}

