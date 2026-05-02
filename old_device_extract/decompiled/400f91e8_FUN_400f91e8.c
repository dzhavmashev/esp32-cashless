// Function : FUN_400f91e8
// Address  : 0x400f91e8
// Size     : 35 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f91e8(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*param_1 == 0) {
    iVar2 = _DAT_3ffc56b8;
  }
  *param_1 = iVar2;
  uVar1 = 0x6003;
  if (iVar2 != 0) {
    memw();
    iVar2 = FUN_401848d4();
    uVar1 = 0x6003;
    if (iVar2 != 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

