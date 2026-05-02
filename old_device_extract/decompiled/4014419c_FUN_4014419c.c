// Function : FUN_4014419c
// Address  : 0x4014419c
// Size     : 70 bytes


undefined4 FUN_4014419c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((*(uint *)(param_1 + 0x118) & 0x800) != 0) {
    param_1 = param_1 + 0x128;
    do {
      iVar2 = *(int *)(param_1 + 4);
      if ((iVar2 == param_3) &&
         (iVar1 = (*(code *)&SUB_4008b33c)(*(undefined4 *)(param_1 + 8),param_2,param_3), iVar1 == 0
         )) {
        return 0;
      }
      if ((iVar2 == 4) &&
         (iVar2 = (*(code *)&SUB_4008b33c)("appen)\n",*(undefined4 *)(param_1 + 8),4), iVar2 == 0))
      {
        return 0;
      }
      param_1 = *(int *)(param_1 + 0xc);
    } while (param_1 != 0);
    uVar3 = 0xffffd800;
  }
  return uVar3;
}

