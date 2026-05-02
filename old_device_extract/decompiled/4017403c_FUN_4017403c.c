// Function : FUN_4017403c
// Address  : 0x4017403c
// Size     : 64 bytes


undefined4 FUN_4017403c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&SUB_4009164c)();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 0)) {
    (*(code *)&SUB_4008a890)();
  }
  uVar2 = FUN_40178024(iVar1,*(undefined4 *)(iVar1 + 8),param_1);
  return uVar2;
}

