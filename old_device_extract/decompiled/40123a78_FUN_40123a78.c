// Function : FUN_40123a78
// Address  : 0x40123a78
// Size     : 46 bytes


undefined4 FUN_40123a78(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_401239f4();
  if (iVar1 == 0) {
    uVar2 = FUN_40123a40(param_1);
  }
  else {
    iVar1 = FUN_40159fd8();
    uVar2 = 0;
    if (iVar1 == 1) {
      FUN_401053bc(param_1,0,0,0);
      uVar2 = 0;
    }
  }
  return uVar2;
}

