// Function : FUN_4011a800
// Address  : 0x4011a800
// Size     : 39 bytes


short FUN_4011a800(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  
  iVar2 = FUN_401189c4(param_1);
  if (((iVar2 < 0) || (sVar1 = *(short *)(iVar2 * 0x30 + 0x3ffc8620), sVar1 == 0)) &&
     (sVar1 = 0x500, param_2 != 0)) {
    sVar1 = *(short *)(param_2 + 0xe2);
  }
  return sVar1;
}

