// Function : FUN_401531a4
// Address  : 0x401531a4
// Size     : 387 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401531a4(int *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  uint *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  int local_40;
  undefined4 *puStack_3c;
  undefined1 *puStack_30;
  
  iVar2 = FUN_40165e58();
  if (iVar2 != 0) {
    iVar2 = *param_1;
    iVar3 = FUN_401530a4(iVar2);
    if (iVar3 != 0) {
      local_40 = 0;
      memw();
      puStack_3c = &local_40;
      sVar1 = (*(code *)&SUB_4000ab7c)(*(ushort *)(iVar2 + 0x16) + 8,4);
      puStack_30 = &DAT_3ffc1a34;
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
      uVar4 = 0;
      puVar7 = (undefined1 *)0x0;
      puVar10 = _DAT_3ffc8fd4;
      while (puVar9 = puVar10, puVar9 != (undefined1 *)0x0) {
        iVar3 = FUN_40151c14(puVar9,sVar1);
        if (iVar3 == 0) goto LAB_401531fc;
        iVar3 = FUN_40153144(iVar2,puVar9);
        if (iVar3 == 0) {
          puVar10 = *(undefined1 **)(puVar9 + 0x28);
        }
        else {
          uVar4 = *(undefined2 *)(puVar9 + 0x16);
          FUN_40151b00(puVar9);
          sVar1 = sVar1 + *(short *)(puVar9 + 0x16);
          puVar10 = *(undefined1 **)(puVar9 + 0x28);
          puVar7 = _DAT_3ffc8fd4;
          if (puVar9 == _DAT_3ffc8fd4) {
            _DAT_3ffc8fd4 = puVar10;
            if (puVar10 == (undefined1 *)0x0) {
              _DAT_3ffc8fd8 = &DAT_3ffc8fd4;
              memw();
            }
          }
          else {
            do {
              puVar6 = puVar7;
              puVar7 = *(undefined1 **)(puVar6 + 0x28);
            } while (puVar9 != *(undefined1 **)(puVar6 + 0x28));
            *(undefined1 **)(puVar6 + 0x28) = puVar10;
            if (puVar10 == (undefined1 *)0x0) {
              _DAT_3ffc8fd8 = puVar6 + 0x28;
            }
          }
          *(undefined4 *)(puVar9 + 0x28) = 0;
          *puStack_3c = puVar9;
          puStack_3c = (undefined4 *)(puVar9 + 0x28);
          puVar7 = puVar9;
          if ((**(uint **)(iVar2 + 0x2c) & 0x8000) == 0) {
            memw();
            puStack_30 = puVar10;
            FUN_40151b00(iVar2);
            **(uint **)(iVar2 + 0x2c) = **(uint **)(iVar2 + 0x2c) | 0x8000;
            puVar10 = puStack_30;
          }
        }
      }
      memw();
LAB_401531fc:
      (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
      if ((**(uint **)(iVar2 + 0x2c) & 0x8000) != 0) {
        iVar3 = FUN_40151be4(puVar7,uVar4,sVar1);
        iVar11 = *(int *)(*(int *)(iVar2 + 4) + 4);
        (*(code *)&SUB_4008b4c8)(iVar11 + 0xe,iVar11,*(undefined2 *)(iVar2 + 0x16));
        *(int *)(*(int *)(iVar2 + 4) + 4) = *(int *)(*(int *)(iVar2 + 4) + 4) + 0xe;
        uVar5 = (uint)*(ushort *)(iVar2 + 0x16);
        memw();
        while (iVar11 = local_40, puVar8 = *(uint **)(iVar2 + 4), local_40 != 0) {
          (*(code *)&SUB_4008b3d0)
                    (puVar8[1] + uVar5,*(undefined4 *)(*(int *)(local_40 + 4) + 4),
                     *(undefined2 *)(local_40 + 0x16));
          uVar5 = uVar5 + *(ushort *)(iVar11 + 0x16) & 0xffff;
          local_40 = *(int *)(iVar11 + 0x28);
          if (local_40 == 0) {
            puStack_3c = &local_40;
          }
          memw();
          FUN_401518bc(iVar11);
        }
        *(short *)(iVar2 + 0x16) = (short)iVar3;
        memw();
        if (puVar8 != (uint *)0x0) {
          memw();
          memw();
          *puVar8 = *puVar8 & 0xfffff000 | iVar3 + 0x2aU & 0xfff;
        }
      }
    }
  }
  memw();
  return;
}

