// Function : FUN_40105c4c
// Address  : 0x40105c4c
// Size     : 62 bytes


undefined4 FUN_40105c4c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&LAB_401850ee_2)(param_1);
  uVar2 = 1;
  if ((((iVar1 != 0x50f200) && (uVar2 = 0x80, iVar1 != 0x50f201)) && (uVar2 = 2, iVar1 != 0x50f202))
     && ((uVar2 = 8, iVar1 != 0x50f204 && (uVar2 = 0, iVar1 == 0x50f205)))) {
    uVar2 = 0x100;
  }
  return uVar2;
}

