// Function : FUN_40105c04
// Address  : 0x40105c04
// Size     : 70 bytes


undefined4 FUN_40105c04(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&LAB_401850ee_2)(param_1);
  uVar2 = 1;
  if ((((iVar1 != 0xfac00) && (uVar2 = 0x80, iVar1 != 0xfac01)) && (uVar2 = 2, iVar1 != 0xfac02)) &&
     (((uVar2 = 8, iVar1 != 0xfac04 && (uVar2 = 0x100, iVar1 != 0xfac05)) &&
      (uVar2 = 0, iVar1 == 0xfac06)))) {
    uVar2 = 0x20;
  }
  return uVar2;
}

