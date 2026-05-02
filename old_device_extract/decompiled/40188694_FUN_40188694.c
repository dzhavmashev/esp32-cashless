// Function : FUN_40188694
// Address  : 0x40188694
// Size     : 355 bytes


uint FUN_40188694(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  iVar4 = *(int *)(param_1 + 0x24);
  if ((**(uint **)(param_1 + 0x2c) & 0x40000) == 0) {
    pbVar5 = *(byte **)(*(int *)(param_1 + 4) + 4);
  }
  else {
    pbVar5 = (byte *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4);
  }
  FUN_401636d0();
  puVar6 = *(uint **)(param_1 + 0x2c);
  uVar8 = puVar6[1];
  if ((uVar8 & 0xf0) == 0x40) {
    puVar6[4] = puVar6[4] & 0xff0fffff | 0x200000;
    memw();
  }
  else {
    uVar7 = puVar6[4];
    if ((iVar4 != 0) && (-1 < *(char *)(iVar4 + 0xb))) {
      bVar1 = *pbVar5;
      uVar3 = bVar1 & 0xc;
      if ((bVar1 & 0xc) == 0) {
        puVar6[4] = uVar7 & 0xff0fffff | (uVar7 >> 0x13 & 1) << 0x14;
        *(uint *)(*(int *)(param_1 + 0x2c) + 4) =
             *(uint *)(*(int *)(param_1 + 0x2c) + 4) & 0xffffff0f;
        *(uint *)(*(int *)(param_1 + 0x2c) + 4) =
             *(uint *)(*(int *)(param_1 + 0x2c) + 4) & 0xfffffff0 | 7;
        memw();
        iVar4 = FUN_401622dc(*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x13 & 1);
        if (iVar4 == 0) {
LAB_401887f4:
          memw();
          return uVar3;
        }
        uVar8 = 1;
        if ((bVar1 & 0xfffffff0) != 0x40) {
          uVar8 = uVar3;
        }
        if (DAT_3ffc1a44 < uVar8) {
          pbVar5[1] = pbVar5[1] | 0x10;
          memw();
          memw();
          return uVar3;
        }
      }
      else {
        uVar3 = uVar8 >> 4 & 0xf;
        uVar7 = uVar7 >> 0x13 & 1;
        uVar2 = *(undefined1 *)(*(int *)(param_1 + 0x24) + 0x80);
        if ((*puVar6 & 0x2000) == 0) {
          uVar8 = FUN_40188498(uVar7,uVar2,uVar8 & 0xf,uVar3);
          if (uVar8 != 0x10) {
            *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) =
                 *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) & 0xff0fffff | (uVar8 & 0xf) << 0x14;
            uVar3 = 0;
            goto LAB_401887f4;
          }
        }
        else {
          uVar8 = FUN_40188498(uVar7,uVar2,uVar8 & 0xf,uVar3);
          if (uVar8 != 0x10) {
            *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) =
                 *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) & 0xff0fffff | (uVar8 & 0xf) << 0x14;
            memw();
            uVar8 = FUN_401622dc(*(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x13 & 1);
            return uVar8;
          }
        }
      }
      return 1;
    }
    puVar6[4] = uVar7 & 0xff0fffff | (uVar7 >> 0x13 & 1) << 0x14;
    *(uint *)(*(int *)(param_1 + 0x2c) + 4) = *(uint *)(*(int *)(param_1 + 0x2c) + 4) & 0xffffff0f;
    *(uint *)(*(int *)(param_1 + 0x2c) + 4) =
         *(uint *)(*(int *)(param_1 + 0x2c) + 4) & 0xfffffff0 | 7;
  }
  memw();
  return 0;
}

