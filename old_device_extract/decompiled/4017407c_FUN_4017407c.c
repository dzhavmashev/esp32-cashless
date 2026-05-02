// Function : FUN_4017407c
// Address  : 0x4017407c
// Size     : 177 bytes


undefined4 FUN_4017407c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_40;
  int iStack_3c;
  undefined *puStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 auStack_24 [9];
  
  iStack_3c = (*(code *)&SUB_4008c01c)(param_2);
  puStack_38 = &DAT_3f421885;
  iStack_28 = iStack_3c + 1;
  uStack_34 = 1;
  uStack_2c = 2;
  local_40 = param_2;
  puStack_30 = (undefined1 *)&local_40;
  if ((param_1 != 0) && (puStack_30 = (undefined1 *)&local_40, *(int *)(param_1 + 0x18) == 0)) {
    puStack_30 = (undefined1 *)&local_40;
    (*(code *)&SUB_4008a890)(param_1);
  }
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 0x18) == 0) {
    (*(code *)&SUB_4008a890)(param_1);
  }
  if (iVar3 == 0x3ff96498) {
    iVar3 = *(int *)(param_1 + 4);
  }
  else if (iVar3 == 0x3ff96478) {
    iVar3 = *(int *)(param_1 + 8);
  }
  else if (iVar3 == 0x3ff96458) {
    iVar3 = *(int *)(param_1 + 0xc);
  }
  FUN_4018560c(1,auStack_24);
  if (((*(uint *)(iVar3 + 100) & 1) == 0) && ((*(ushort *)(iVar3 + 0xc) & 0x200) == 0)) {
    (*(code *)&SUB_40086504)(*(undefined4 *)(iVar3 + 0x58));
  }
  iVar1 = (*(code *)&SUB_4008a9b8)(param_1,iVar3,&puStack_30);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = 10;
  }
  if (((*(uint *)(iVar3 + 100) & 1) == 0) && ((*(ushort *)(iVar3 + 0xc) & 0x200) == 0)) {
    (*(code *)&SUB_40086534)(*(undefined4 *)(iVar3 + 0x58));
  }
  FUN_4018560c(auStack_24[0],auStack_24);
  return uVar2;
}

