// Function : FUN_40124438
// Address  : 0x40124438
// Size     : 24 bytes


undefined4 FUN_40124438(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4015a398();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_40124030(*(undefined4 *)(iVar1 + 4),param_1,param_2);
  }
  return uVar2;
}

