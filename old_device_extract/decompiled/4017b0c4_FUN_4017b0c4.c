// Function : FUN_4017b0c4
// Address  : 0x4017b0c4
// Size     : 52 bytes


undefined4 FUN_4017b0c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&SUB_4009164c)();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 0)) {
    (*(code *)&SUB_4008a890)();
  }
  uVar2 = FUN_40178024(iVar1,*(undefined4 *)(iVar1 + 8),param_1,param_2,param_3,param_4);
  return uVar2;
}

