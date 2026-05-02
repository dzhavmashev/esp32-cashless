// Function : FUN_400e0768
// Address  : 0x400e0768
// Size     : 40 bytes


undefined4 FUN_400e0768(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 4);
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  FUN_400d48f8(uVar3,uVar1);
  iVar2 = (*(code *)&LAB_4018416e_2)();
  if (iVar2 != 0) {
    FUN_400d48f8(uVar3,uVar1);
    param_2 = FUN_400e0588();
  }
  return param_2;
}

