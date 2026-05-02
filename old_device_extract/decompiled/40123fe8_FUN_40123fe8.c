// Function : FUN_40123fe8
// Address  : 0x40123fe8
// Size     : 69 bytes


undefined4 FUN_40123fe8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x3c) != 0) {
    if (*(int *)(param_1 + 0x38) == 0) {
      iVar1 = (*(code *)&SUB_40094dd8)(1,0x30);
      *(int *)(param_1 + 0x38) = iVar1;
      uVar2 = 0xffffffff;
      if (iVar1 == 0) goto LAB_40124026;
      memw();
      uVar2 = FUN_40159f40();
      (*(code *)&SUB_4008b3d0)(iVar1 + 8,uVar2,0x20);
    }
    uVar2 = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x38) + 4) = 1;
  }
LAB_40124026:
  memw();
  return uVar2;
}

