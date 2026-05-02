// Function : FUN_4016e840
// Address  : 0x4016e840
// Size     : 1198 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e840(byte *param_1,undefined1 *param_2,undefined1 *param_3,byte *param_4,byte *param_5,
                 byte *param_6,byte *param_7,byte param_8,char *param_9)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *UNRECOVERED_JUMPTABLE;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
  uint *puVar9;
  
  uVar5 = (uint)param_8;
  uVar2 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c4);
  _DAT_3ff4e0c4 = (uVar5 & 0x1f) << 10 | uVar2 & 0xffff83ff;
  memw();
  if (uVar5 == 0) {
    memw();
    _DAT_3ff4e164 = uVar5;
    return;
  }
  uVar2 = 0;
  _DAT_3ff4e164 = 0;
  do {
    if (*param_9 == '\x01') {
      _DAT_3ff4e164 = _DAT_3ff4e164 + (1 << 0x20 - (0x20 - (uVar2 & 0x1f)));
    }
    uVar2 = uVar2 + 1;
    param_9 = param_9 + 1;
  } while ((uVar2 & 0xff) < uVar5);
  memw();
  uVar2 = 0;
  do {
    uVar3 = (uVar2 & 0xff) >> 3;
    if (uVar3 == 0) {
      uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e100);
      _DAT_3ff4e100 =
           (0xf << 0x20 - (0x20 - (uVar2 << 2 & 0x1f)) ^ 0xffffffffU) & uVar3 |
           (*param_1 & 0xf) << 0x20 - (0x20 - (uVar2 << 2 & 0x1f));
      memw();
    }
    else if (uVar3 == 1) {
      uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e104);
      _DAT_3ff4e104 =
           (0xf << 0x20 - ((uVar2 & 7) * -4 + 0x20) ^ 0xffffffffU) & uVar3 |
           (*param_1 & 0xf) << 0x20 - ((uVar2 & 7) * -4 + 0x20);
      memw();
    }
    else {
      uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e108);
      _DAT_3ff4e108 =
           (0xf << 0x20 - ((uVar2 & 7) * -4 + 0x20) ^ 0xffffffffU) & uVar3 |
           (*param_1 & 0xf) << 0x20 - ((uVar2 & 7) * -4 + 0x20);
      memw();
    }
    uVar2 = uVar2 + 1;
    param_1 = param_1 + 1;
  } while ((uVar5 - 1 & 0xff) + 1 != uVar2);
  uVar3 = 0;
  uVar2 = 0;
  do {
    if (uVar2 >> 1 < 9) {
      UNRECOVERED_JUMPTABLE = *(code **)((uVar2 >> 1) * 4 + 0x3ffc3ae4);
                    /* WARNING: Could not emulate address calculation at 0x4016e98b */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(8,UNRECOVERED_JUMPTABLE);
      return;
    }
    uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff4e110);
    _DAT_3ff4e110 =
         (uint)CONCAT11(*param_3,*param_2) << 0x20 - ((uVar2 & 1) * -0x10 + 0x20) |
         (0xffff << 0x20 - ((uVar2 & 1) * -0x10 + 0x20) ^ 0xffffffffU) & uVar4;
    memw();
    uVar3 = uVar3 + 1;
    uVar2 = uVar3 & 0xff;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  } while (uVar2 < uVar5);
  uVar2 = 0;
  uVar3 = 0;
  pbVar6 = param_6;
  pbVar7 = param_4;
  do {
    uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff4e128);
    uVar8 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f)) ^ 0xffffffff;
    _DAT_3ff4e128 = (*pbVar6 >> 4 & 1) << 0x20 - (0x20 - (uVar2 & 0x1f)) | uVar4 & uVar8;
    memw();
    uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff4e12c);
    _DAT_3ff4e12c = (*pbVar7 >> 4 & 1) << 0x20 - (0x20 - (uVar2 & 0x1f)) | uVar8 & uVar4;
    memw();
    if (uVar3 >> 3 == 0) {
      uVar8 = uVar2 << 2;
      uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e0d0);
      uVar4 = 0xf << 0x20 - (0x20 - (uVar8 & 0x1f)) ^ 0xffffffff;
      _DAT_3ff4e0d0 = (*pbVar6 & 0xf) << 0x20 - (0x20 - (uVar8 & 0x1f)) | uVar3 & uVar4;
      memw();
      uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e11c);
      _DAT_3ff4e11c = (*pbVar7 & 0xf) << 0x20 - (0x20 - (uVar8 & 0x1f)) | uVar4 & uVar3;
      memw();
    }
    else if (uVar3 >> 3 == 1) {
      uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff4e0d4);
      uVar3 = uVar3 & 7;
      uVar8 = 0xf << 0x20 - (uVar3 * -4 + 0x20) ^ 0xffffffff;
      _DAT_3ff4e0d4 = (*pbVar6 & 0xf) << 0x20 - (uVar3 * -4 + 0x20) | uVar4 & uVar8;
      memw();
      uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff4e120);
      _DAT_3ff4e120 = (*pbVar7 & 0xf) << 0x20 - (uVar3 * -4 + 0x20) | uVar8 & uVar4;
      memw();
    }
    else {
      uVar3 = uVar3 & 7;
      uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff4e124);
      _DAT_3ff4e124 =
           (0xf << 0x20 - (uVar3 * -4 + 0x20) ^ 0xffffffffU) & uVar4 |
           (*pbVar6 & 0xf) << 0x20 - (uVar3 * -4 + 0x20);
      memw();
      uVar4 = (*(code *)&SUB_40084594)(&DAT_3ff4e124);
      uVar3 = uVar3 * 4 + 0x10;
      _DAT_3ff4e124 =
           (0xf << 0x20 - (0x20 - (uVar3 & 0x1f)) ^ 0xffffffffU) & uVar4 |
           (*pbVar7 & 0xf) << 0x20 - (0x20 - (uVar3 & 0x1f));
      memw();
    }
    uVar2 = uVar2 + 1;
    uVar3 = uVar2 & 0xff;
    pbVar6 = pbVar6 + 1;
    pbVar7 = pbVar7 + 1;
  } while (uVar3 < uVar5);
  uVar2 = 0;
  do {
    bVar1 = *param_6 >> 2;
    if (bVar1 == 1) {
      uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e0cc);
      _DAT_3ff4e0cc =
           (0xff << 0x20 - ((*param_6 & 3) * -8 + 0x20) ^ 0xffffffffU) & uVar3 |
           (uint)*param_7 << 0x20 - ((*param_6 & 3) * -8 + 0x20);
      memw();
    }
    else if (bVar1 == 0) {
      uVar3 = (*(code *)&SUB_40084594)(&DAT_3ff4e0c8);
      _DAT_3ff4e0c8 =
           (0xff << 0x20 - ((*param_6 & 3) * -8 + 0x20) ^ 0xffffffffU) & uVar3 |
           (uint)*param_7 << 0x20 - ((*param_6 & 3) * -8 + 0x20);
      memw();
    }
    else {
      if (bVar1 == 2) {
        puVar9 = (uint *)&DAT_3ff4e114;
      }
      else {
        if (bVar1 != 3) goto code_r0x4016ed07;
        puVar9 = (uint *)&DAT_3ff4e118;
      }
      uVar3 = (*(code *)&SUB_40084594)(puVar9);
      memw();
      *puVar9 = (0xff << 0x20 - ((*param_6 & 3) * -8 + 0x20) ^ 0xffffffffU) & uVar3 |
                (uint)*param_7 << 0x20 - ((*param_6 & 3) * -8 + 0x20);
    }
code_r0x4016ed07:
    bVar1 = *param_4 >> 2;
    if (bVar1 == 1) {
      puVar9 = (uint *)&DAT_3ff4e0cc;
LAB_4016ed38:
      uVar3 = (*(code *)&SUB_40084594)(puVar9);
      memw();
      *puVar9 = (0xff << 0x20 - ((*param_4 & 3) * -8 + 0x20) ^ 0xffffffffU) & uVar3 |
                (uint)*param_5 << 0x20 - ((*param_4 & 3) * -8 + 0x20);
    }
    else {
      if (bVar1 == 0) {
        puVar9 = (uint *)&DAT_3ff4e0c8;
        goto LAB_4016ed38;
      }
      if (bVar1 == 2) {
        puVar9 = (uint *)&DAT_3ff4e114;
        goto LAB_4016ed38;
      }
      if (bVar1 == 3) {
        puVar9 = (uint *)&DAT_3ff4e118;
        goto LAB_4016ed38;
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
    param_6 = param_6 + 1;
    param_4 = param_4 + 1;
    param_5 = param_5 + 1;
    param_7 = param_7 + 1;
    if (uVar5 <= uVar2) {
      return;
    }
  } while( true );
}

