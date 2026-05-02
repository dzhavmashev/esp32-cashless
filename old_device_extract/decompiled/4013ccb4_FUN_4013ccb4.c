// Function : FUN_4013ccb4
// Address  : 0x4013ccb4
// Size     : 450 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_4013ccb4(int param_1,uint param_2,uint param_3,uint param_4,byte *param_5,byte *param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  uint in_t0;
  byte bStack_68;
  byte bStack_64;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  byte local_34 [16];
  uint uStack_24;
  
  memw();
  iVar2 = -0x22;
  memw();
  uStack_24 = _DAT_3ffc5708;
  iVar4 = 0xfffff0;
  if (param_3 - 0x10 < 0xfffff1) {
    memw();
    iVar2 = FUN_4013cf6c(param_1 + 0x22,1,param_4,&local_54);
    iVar4 = iVar2;
    if (iVar2 == 0) {
      uVar7 = param_3 & 0xf;
      param_4 = param_3 >> 4;
      uVar5 = 1;
      bStack_68 = uVar7 != 0;
      bStack_64 = param_2 == 0;
      iVar3 = iVar2;
      goto LAB_4013cd03;
    }
  }
LAB_4013cda8:
  do {
    uVar7 = in_t0;
    uVar5 = uStack_24;
    param_2 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return iVar2;
    }
    memw();
    (*(code *)&SUB_40082ec4)(iVar4);
    iVar3 = iVar2;
    in_t0 = uVar7;
    do {
      if ((bStack_68 & bStack_64) != 0) {
        uVar9 = 0;
        if (param_4 == 0) {
          uVar9 = uVar5;
        }
        if ((uVar9 & 0xff) != 0) {
          uStack_44 = local_54;
          uStack_40 = uStack_50;
          uStack_3c = uStack_4c;
          uStack_38 = uStack_48;
          memw();
          FUN_40186594(&local_54);
        }
      }
      local_34[0] = *param_5 ^ (byte)local_54;
      memw();
      memw();
      iVar2 = FUN_4013cf6c(param_1,param_2,local_34);
      iVar4 = iVar2;
      if (iVar2 != 0) goto LAB_4013cda8;
      *param_6 = local_34[0] ^ (byte)local_54;
      memw();
      memw();
      iVar4 = FUN_40186594(&local_54,&local_54);
      param_6 = param_6 + 0x10;
      param_5 = param_5 + 0x10;
LAB_4013cd03:
      param_4 = param_4 - 1;
    } while (param_4 != 0xffffffff);
    iVar2 = iVar3;
    if (uVar7 != 0) {
      pbVar6 = (byte *)&uStack_44;
      if (param_2 != 0) {
        pbVar6 = (byte *)&local_54;
      }
      *param_6 = param_6[-0x10];
      memw();
      local_34[0] = *param_5 ^ *pbVar6;
      memw();
      iVar2 = 0x10 - uVar7;
      do {
        iVar4 = uVar7 - 0x10;
        pbVar8 = local_34 + uVar7;
        pbVar10 = pbVar6 + uVar7;
        uVar7 = uVar7 + 1;
        param_5 = (byte *)(uint)(param_6[iVar4] ^ *pbVar10);
        *pbVar8 = param_6[iVar4] ^ *pbVar10;
        memw();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      memw();
      iVar2 = FUN_4013cf6c(param_1,param_2,local_34);
      param_4 = 0;
      iVar4 = iVar2;
      if (iVar2 == 0) {
        param_5 = (byte *)(uint)*pbVar6;
        bVar1 = local_34[0] ^ *pbVar6;
        param_4 = (uint)bVar1;
        param_6[-0x10] = bVar1;
        memw();
        iVar2 = iVar3;
        iVar4 = 1;
      }
    }
  } while( true );
}

