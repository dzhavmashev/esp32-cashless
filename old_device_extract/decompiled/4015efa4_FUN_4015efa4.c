// Function : FUN_4015efa4
// Address  : 0x4015efa4
// Size     : 80 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015efa4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_30 [12];
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
  iVar1 = FUN_4015ed68(iVar2 + 10);
  if ((iVar1 != 0) &&
     (iVar1 = (*_DAT_3ffc8acc)(iVar1 + 0xa8,iVar2,iVar2 + 0x18,*(undefined2 *)(param_1 + 0x16),
                               local_30,1), iVar1 != 0)) {
    (*(code *)&SUB_4008b3d0)(iVar2 + 0x20,iVar1,local_30[0]);
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar1);
    return 0;
  }
  return 0xffffffff;
}

