// Function : FUN_401635f4
// Address  : 0x401635f4
// Size     : 214 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401635f4(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  puVar6 = _DAT_3ffc0034;
  param_1 = param_1 & 0xff;
  uVar1 = 0;
  if ((*_DAT_3ffc0034 | 7) != 0xffff) {
    uVar3 = _DAT_3ffc0034[param_1 * 2 + 0xcd];
    if (uVar3 == 0) {
      uVar1 = 0;
    }
    else {
      iVar2 = param_1 + 0x66;
      puVar4 = _DAT_3ffc0034 + iVar2 * 2 + 1;
      _DAT_3ffc0034[param_1 * 2 + 0xcd] = 0;
      puVar6[param_1 * 2 + 0xce] = (uint)puVar4;
      do {
        uVar8 = *(uint *)(*(int *)(uVar3 + 0x2c) + 4);
        uVar5 = *(uint *)(uVar3 + 0x28);
        uVar7 = *(uint *)(*(int *)(uVar3 + 0x2c) + 0x10);
        *(undefined4 *)(uVar3 + 0x28) = 0;
        memw();
        uVar7 = FUN_40188498(uVar7 >> 0x13 & 1,*(undefined1 *)(*(int *)(uVar3 + 0x24) + 0x80),
                             uVar8 & 0xf,uVar8 >> 4 & 0xf);
        if (uVar7 == 0x10) {
          puVar6 = (uint *)_DAT_3ffc0034[iVar2 * 2 + 2];
          *(undefined4 *)(uVar3 + 0x28) = 0;
          *puVar6 = uVar3;
          _DAT_3ffc0034[iVar2 * 2 + 2] = uVar3 + 0x28;
          memw();
        }
        else {
          *(uint *)(*(int *)(uVar3 + 0x2c) + 0x10) =
               *(uint *)(*(int *)(uVar3 + 0x2c) + 0x10) & 0xff0fffff | (uVar7 & 0xf) << 0x14;
          puVar6 = (uint *)_DAT_3ffc0034
                           [(*(uint *)(*(int *)(uVar3 + 0x2c) + 0x10) >> 0x14 & 0xf) * 0xc + 9];
          *(undefined4 *)(uVar3 + 0x28) = 0;
          *puVar6 = uVar3;
          _DAT_3ffc0034[(*(uint *)(*(int *)(uVar3 + 0x2c) + 0x10) >> 0x14 & 0xf) * 0xc + 9] =
               uVar3 + 0x28;
          memw();
          (*(code *)&SUB_40087bcc)(*(uint *)(*(int *)(uVar3 + 0x2c) + 4) >> 4 & 0xf,0);
        }
        uVar3 = uVar5;
      } while (uVar5 != 0);
      uVar1 = 1;
    }
  }
  return uVar1;
}

