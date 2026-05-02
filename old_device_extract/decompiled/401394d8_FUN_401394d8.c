// Function : FUN_401394d8
// Address  : 0x401394d8
// Size     : 33 bytes


undefined4 FUN_401394d8(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0xffffffd2;
  if (param_1 != 0) {
    iVar2 = FUN_40139474();
    uVar1 = 0xffffffd2;
    if (iVar2 != 0) {
      uVar1 = 0;
      *param_2 = *(undefined4 *)(iVar2 + 0x10);
      *param_3 = *(undefined4 *)(iVar2 + 0x14);
    }
  }
  memw();
  return uVar1;
}

