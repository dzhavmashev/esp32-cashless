// Function : FUN_40100790
// Address  : 0x40100790
// Size     : 42 bytes


undefined4 FUN_40100790(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  iVar1 = (*(code *)&SUB_4008b3d0)(*(undefined4 *)(param_1 + 0xc),uVar2,6);
  (*(code *)&SUB_4008b3d0)(*(int *)(iVar1 + 0x10) + 0xe4,uVar2,6);
  return 0;
}

