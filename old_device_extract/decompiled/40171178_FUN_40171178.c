// Function : FUN_40171178
// Address  : 0x40171178
// Size     : 156 bytes


undefined4 FUN_40171178(int param_1)

{
  uint unaff_retaddr;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int in_t0;
  int local_a0 [14];
  int local_68 [14];
  undefined1 auStack_30 [48];
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar1 = FUN_40170f54(param_1);
  }
  else {
    (*(code *)&SUB_40092e4c)();
    FUN_40170bac(local_68,&stack0x00000000,unaff_retaddr & 0x3fffffff | 0x40000000);
    (*(code *)&SUB_4008b3d0)(local_a0,local_68);
    iVar2 = FUN_40170e64(param_1,local_a0,auStack_30);
    iVar3 = 0;
    uVar8 = 0;
    if (iVar2 != 7) {
      iVar3 = in_t0;
      (*(code *)&SUB_40094bc8)();
    }
    do {
      uVar1 = 1;
      puVar6 = *(undefined4 **)((int)local_68 + iVar3);
      puVar7 = *(undefined4 **)((int)local_a0 + iVar3);
      uVar5 = uVar8;
      if (puVar7 != (undefined4 *)0x0) {
        uVar5 = 1;
      }
      uVar4 = uVar8;
      if (puVar6 != (undefined4 *)0x0) {
        uVar4 = 1;
      }
      if (((uVar5 & uVar4) != 0) && (puVar6 != puVar7)) {
        *puVar6 = *puVar7;
      }
      iVar3 = iVar3 + 4;
    } while (iVar3 != 8);
  }
  return uVar1;
}

