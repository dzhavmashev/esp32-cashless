// Function : FUN_4011eb64
// Address  : 0x4011eb64
// Size     : 261 bytes


int FUN_4011eb64(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  ushort *puVar8;
  undefined1 in_PRID;
  undefined8 uVar9;
  
  if (param_1 == (int *)0x0) {
    iVar1 = 0x102;
  }
  else {
    uVar5 = *(uint *)*param_1 >> 0x10 & 1;
    uVar2 = rsr(in_PRID);
    if (uVar5 == (uVar2 >> 0xd & 1)) {
      (*(code *)&SUB_40092a98)(0x3ffbe108,0xffffffff);
      (*(code *)&SUB_400844a4)(param_1);
      puVar8 = (ushort *)*param_1;
      uVar4 = *puVar8 & 4;
      if ((*puVar8 & 4) != 0) {
        uVar9 = CONCAT44(puVar8,*(int *)(puVar8 + 2));
        if (*(int *)(puVar8 + 2) == 0) {
          uVar9 = (*(code *)&SUB_40094c54)("support/intr_alloc.c",0x28d,"disable","!= NULL");
        }
        iVar1 = 0;
        iVar6 = (int)uVar9;
        do {
          iVar3 = *(int *)(iVar6 + 0x14);
          if (param_1[1] == iVar6) {
            if (iVar1 == 0) {
              *(int *)((int)((ulonglong)uVar9 >> 0x20) + 4) = iVar3;
              memw();
            }
            else {
              *(int *)(iVar1 + 0x14) = iVar3;
            }
            memw();
            (*(code *)&SUB_40094d80)();
            break;
          }
          iVar1 = iVar6;
          iVar6 = iVar3;
        } while (iVar3 != 0);
        uVar4 = (ushort)(*(int *)(*param_1 + 4) == 0);
      }
      if (((*(uint *)*param_1 & 8) != 0) || (uVar4 != 0)) {
        uVar2 = *(uint *)*param_1 >> 0x11 & 0x1f;
        FUN_4011f6cc(uVar2,0,uVar2);
        uVar2 = *(uint *)*param_1;
        *(uint *)*param_1 = uVar2 & 0xc03f0000 | 0x27400000;
        puVar7 = (uint *)(((uVar2 & 0x10000) >> 0x10) * 4 + 0x3ffc66d8);
        *puVar7 = (uint)(0xfffffffefffffffe >> 0x20 - ((uVar2 & 0x3e0000) >> 0x11)) & *puVar7;
      }
      memw();
      (*(code *)&SUB_40092bec)(0x3ffbe108);
      (*(code *)&SUB_40094d80)(param_1);
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_401217cc(uVar5,0x4011ec64,param_1);
      iVar1 = -(uint)(iVar1 != 0);
    }
  }
  return iVar1;
}

