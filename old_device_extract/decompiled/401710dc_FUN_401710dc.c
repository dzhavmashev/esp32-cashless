// Function : FUN_401710dc
// Address  : 0x401710dc
// Size     : 154 bytes


int FUN_401710dc(int param_1)

{
  uint unaff_retaddr;
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int in_t0;
  undefined4 local_a0 [6];
  int iStack_88;
  undefined4 local_68 [14];
  undefined1 auStack_30 [48];
  
  (*(code *)&SUB_40092e4c)();
  FUN_40170bac(local_68,&stack0x00000000,unaff_retaddr & 0x3fffffff | 0x40000000);
  (*(code *)&SUB_4008b3d0)(local_a0,local_68);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = FUN_40170e00();
  }
  else {
    iVar1 = FUN_40170e64(param_1,local_a0,auStack_30);
  }
  iVar3 = 0;
  uVar7 = 0;
  if (iVar1 != 7) {
    iVar3 = in_t0;
    (*(code *)&SUB_40094bc8)();
  }
  do {
    puVar5 = *(undefined4 **)((int)local_68 + iVar3);
    puVar6 = *(undefined4 **)((int)local_a0 + iVar3);
    uVar4 = uVar7;
    if (puVar6 != (undefined4 *)0x0) {
      uVar4 = 1;
    }
    uVar2 = uVar7;
    if (puVar5 != (undefined4 *)0x0) {
      uVar2 = 1;
    }
    if (((uVar4 & uVar2) != 0) && (puVar5 != puVar6)) {
      *puVar5 = *puVar6;
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 != 8);
  return iStack_88 * 4 + 2;
}

