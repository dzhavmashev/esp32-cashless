// Function : FUN_400f112c
// Address  : 0x400f112c
// Size     : 98 bytes


uint FUN_400f112c(byte *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = param_1;
  if (((param_1[0xf] & 0x80) == 0) && (pbVar3 = *(byte **)param_1, pbVar3 == (byte *)0x0)) {
    if (-1 < (char)param_2[0xf]) goto LAB_400f1161;
  }
  else {
    pbVar4 = param_2;
    if (((char)param_2[0xf] < '\0') || (pbVar4 = *(byte **)param_2, pbVar4 != (byte *)0x0)) {
      uVar1 = func_0x4008bdf4(pbVar3,pbVar4);
      return uVar1;
    }
LAB_400f1161:
    param_2 = *(byte **)param_2;
    if (param_2 == (byte *)0x0) goto LAB_400f1178;
  }
  iVar2 = FUN_40184778();
  if (iVar2 != 0) {
    return -(uint)*param_2;
  }
LAB_400f1178:
  uVar1 = 0;
  if (pbVar3 != (byte *)0x0) {
    iVar2 = FUN_40184778(param_1);
    uVar1 = 0;
    if (iVar2 != 0) {
      uVar1 = (uint)*pbVar3;
    }
  }
  return uVar1;
}

