// Function : FUN_4016c698
// Address  : 0x4016c698
// Size     : 1642 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016c698(undefined4 param_1,uint param_2,uint param_3,short *param_4,int *param_5,
                 char *param_6)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  char cVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int aiStack_190 [15];
  int local_154 [16];
  int local_114 [16];
  int local_d4;
  short asStack_d0 [15];
  short local_b2;
  short asStack_b0 [15];
  short local_92;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int *piStack_70;
  short *psStack_6c;
  int iStack_68;
  int iStack_64;
  short *psStack_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  int iStack_50;
  int iStack_4c;
  uint uStack_48;
  int iStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  char *pcStack_34;
  int iStack_30;
  int iStack_2c;
  
  uStack_54 = param_2 & 0xff;
  uStack_48 = param_3 & 0xffff;
  iStack_44 = 8;
  if (uStack_54 != 1) {
    iStack_44 = 0x10;
  }
  psStack_6c = (short *)(int)*param_4;
  iStack_68 = (int)param_4[1];
  iStack_84 = 0;
  iStack_80 = 0;
  iStack_7c = 0;
  iStack_90 = 0;
  iStack_8c = 0;
  iStack_88 = 0;
  psStack_60 = param_4;
  pcStack_34 = param_6;
  uVar3 = (**(code **)(_DAT_3ffc7e64 + 0xbc))(1,2);
  uStack_40 = (**(code **)(_DAT_3ffc7e64 + 0xbc))(0,1);
  uStack_3c = uVar3 & 1;
  if ((uStack_3c < 3) || (uStack_54 != 1)) {
    cVar10 = '\x01';
  }
  else {
    cVar10 = (char)uStack_3c + -1;
  }
  iStack_4c = (uStack_54 == 1) + 1;
  iVar11 = (int)cVar10;
  iStack_64 = 0;
  uStack_38 = uStack_3c - 1 & 0xff;
  *pcStack_34 = '\0';
  uStack_5c = 0;
  do {
    uStack_58 = (uint)psStack_6c & 0xffff;
    pcVar4 = *(code **)(_DAT_3ffc7e64 + 0xb8);
    *psStack_60 = (short)psStack_6c;
    psStack_60[1] = (short)iStack_68;
    memw();
    (*pcVar4)(2,iStack_4c,uStack_58);
    (**(code **)(_DAT_3ffc7e64 + 0xb8))(3,iStack_4c,psStack_60[1]);
    if (uStack_54 == 1) {
      (*(code *)&SUB_40008534)(10);
      FUN_4016c634(uStack_48,uStack_54,param_5);
      iStack_50 = param_5[2];
      if (uStack_3c < 2) {
        iVar5 = 2;
        uVar3 = 0;
        iVar14 = *param_5;
      }
      else {
        iVar14 = *param_5;
        iVar5 = 2;
        uVar3 = uStack_38;
      }
    }
    else {
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,0);
      (*(code *)&SUB_40008534)(10);
      FUN_4016c634(uStack_48,1,&iStack_84);
      (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,0x20);
      (*(code *)&SUB_40008534)(10);
      FUN_4016c634(uStack_48,1,&iStack_90);
      uVar3 = 0;
      iVar5 = 1;
      iVar14 = iStack_90 - iStack_84;
      iStack_50 = (uint)(iStack_88 < iStack_7c) * iStack_7c +
                  (uint)(iStack_88 >= iStack_7c) * iStack_88;
      *param_5 = iVar14;
      param_5[1] = iStack_8c - iStack_80;
    }
    iVar14 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iVar14);
    if (iVar14 < iVar11) {
      iVar14 = (**(code **)(_DAT_3ffc7e64 + 0x140))(param_5[1]);
      if (iVar14 < iVar11) {
        iVar5 = 0;
      }
      else {
        iVar5 = (int)(short)(iVar5 * param_5[1] >> (uVar3 & 0x1f));
      }
LAB_4016c8c3:
      iVar14 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iStack_84);
      if (iVar14 < 0x32) {
        iVar7 = 1;
        if (*param_5 < 1) {
          iVar7 = -(uint)(*param_5 != 0);
        }
      }
      else {
        iVar7 = (int)(short)(iStack_84 >> (uVar3 & 0x1f));
      }
LAB_4016c8f1:
      if (iVar5 == 0) goto LAB_4016c8f3;
    }
    else {
      iVar7 = (int)(short)(iVar5 * *param_5 >> (uVar3 & 0x1f));
      iVar14 = (**(code **)(_DAT_3ffc7e64 + 0x140))(param_5[1]);
      if (iVar11 <= iVar14) {
        iVar5 = (int)(short)(iVar5 * param_5[1] >> (uVar3 & 0x1f));
        if (iVar7 == 0) goto LAB_4016c8c3;
        goto LAB_4016c8f1;
      }
      if (iVar7 == 0) {
        iVar5 = 0;
        goto LAB_4016c8c3;
      }
LAB_4016c8f3:
      iVar5 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iStack_80);
      if (iVar5 < 0x32) {
        iVar5 = 1;
        if (param_5[1] < 1) {
          iVar5 = -(uint)(param_5[1] != 0);
        }
      }
      else {
        iVar5 = (int)(short)(iStack_80 >> (uVar3 & 0x1f));
      }
    }
    if (uStack_54 == 1) {
      iVar15 = *param_5;
    }
    else {
      if ((0x33 < iStack_7c) || (0x33 < iStack_88)) {
        iVar5 = 0;
        iVar7 = 0;
      }
      if (0x186 < uStack_40) {
        sVar2 = (**(code **)(_DAT_3ffc7e64 + 0x2c))(iVar7,5,0xfffffffb);
        iVar7 = (int)sVar2;
        sVar2 = (**(code **)(_DAT_3ffc7e64 + 0x2c))(iVar5,5,0xfffffffb);
        iVar5 = (int)sVar2;
      }
      iVar14 = iStack_64;
      piVar6 = aiStack_190 + iStack_64;
      asStack_b0[iStack_64] = (short)psStack_6c;
      memw();
      iVar15 = *param_5;
      iVar13 = param_5[1];
      asStack_d0[iVar14] = (short)iStack_68;
      iVar1 = iStack_50;
      memw();
      local_114[iVar14 + 1] = iVar15;
      local_154[iVar14 + 1] = iVar13;
      *piVar6 = iVar1;
    }
    iVar14 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iVar15);
    if (((iVar14 <= iVar11) &&
        (iVar14 = (**(code **)(_DAT_3ffc7e64 + 0x140))(param_5[1]), iStack_50 < 0x31)) &&
       (iVar14 <= iVar11)) {
      iVar11 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iStack_84);
      if ((iVar11 < 0x1e) &&
         (iVar11 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iStack_80), iVar11 < 0x1e)) {
        *pcStack_34 = '\x01';
        memw();
        goto code_r0x4016cc19;
      }
      break;
    }
    iVar14 = (**(code **)(_DAT_3ffc7e64 + 0x140))(*param_5);
    if (iVar11 < iVar14) {
      psStack_6c = (short *)(int)(short)((short)uStack_58 - (short)iVar7);
    }
    iVar14 = (**(code **)(_DAT_3ffc7e64 + 0x140))(param_5[1]);
    if (iVar11 < iVar14) {
      iStack_68 = (int)(short)((short)iStack_68 - (short)iVar5);
    }
    uVar3 = uStack_5c + 1;
    uStack_5c = uVar3 & 0xff;
    iVar5 = (uint)((int)psStack_6c < 0x1ff) * (int)psStack_6c +
            (uint)((int)psStack_6c >= 0x1ff) * 0x1ff;
    iStack_68 = (uint)(iStack_68 < 0x1ff) * iStack_68 + (uint)(iStack_68 >= 0x1ff) * 0x1ff;
    psStack_6c = (short *)((uint)(-1 < iVar5) * iVar5);
    iStack_68 = (uint)(-1 < iStack_68) * iStack_68;
    iStack_64 = (int)(char)uVar3;
  } while (iStack_64 < iStack_44);
  if (((uStack_54 != 1) && (*pcStack_34 == '\0')) && ('\x0e' < (char)uStack_5c)) {
    if (0x30 < iStack_50) {
      *param_5 = 100;
      param_5[1] = 100;
    }
    iStack_64 = 0;
    piVar9 = &local_d4;
    piVar6 = local_114;
    psVar12 = &local_92;
    psStack_6c = &local_b2;
    piVar8 = local_154;
    piStack_70 = piVar6;
    iStack_68 = 0;
    do {
      iStack_2c = *piVar9;
      iStack_30 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iStack_2c);
      iVar5 = (**(code **)(_DAT_3ffc7e64 + 0x140))(*param_5);
      iVar11 = _DAT_3ffc7e64;
      if (iStack_30 < iVar5) {
        if (0x30 < *piVar8) {
          (**(code **)(_DAT_3ffc7e64 + 0x140))(*piVar6);
          (**(code **)(_DAT_3ffc7e64 + 0x140))(param_5[1]);
LAB_4016cbb4:
          if (iStack_68 == 0) goto LAB_4016cbb9;
LAB_4016cbcd:
          iStack_68 = 1;
          goto code_r0x4016cbda;
        }
        iStack_30 = *piVar6;
        *psStack_60 = *psVar12;
        memw();
        pcVar4 = *(code **)(iVar11 + 0x140);
        *param_5 = iStack_2c;
        iStack_2c = (*pcVar4)(iStack_30);
        iVar11 = (**(code **)(_DAT_3ffc7e64 + 0x140))(param_5[1]);
        if (iVar11 <= iStack_2c) goto LAB_4016cbcd;
        iStack_64 = 1;
        iStack_68 = 1;
        psStack_60[1] = *psStack_6c;
        param_5[1] = iStack_30;
      }
      else {
        iStack_2c = *piVar6;
        iStack_30 = (**(code **)(_DAT_3ffc7e64 + 0x140))(iStack_2c);
        iVar11 = (**(code **)(_DAT_3ffc7e64 + 0x140))(param_5[1]);
        if ((iVar11 <= iStack_30) || (0x30 < *piVar8)) goto LAB_4016cbb4;
        psStack_60[1] = *psStack_6c;
        param_5[1] = iStack_2c;
        iStack_64 = 1;
        if (iStack_68 != 0) {
          iStack_68 = 1;
          goto LAB_4016cbf3;
        }
LAB_4016cbb9:
        iStack_68 = 0;
        *psStack_60 = asStack_b0[0];
        memw();
code_r0x4016cbda:
        if (iStack_64 == 0) {
          psStack_60[1] = asStack_d0[0];
          memw();
        }
        else {
          iStack_64 = 1;
        }
      }
LAB_4016cbf3:
      piVar9 = piVar9 + -1;
      piVar8 = piVar8 + -1;
      psVar12 = psVar12 + -1;
      piVar6 = piVar6 + -1;
      psStack_6c = psStack_6c + -1;
    } while (piStack_70 != piVar9);
  }
code_r0x4016cc19:
  iVar11 = (int)*psStack_60;
  if (iVar11 < 0) {
    iVar11 = 0;
    *psStack_60 = 0;
    memw();
  }
  else if (0x1ff < iVar11) {
    iVar11 = 0x1ff;
    *psStack_60 = 0x1ff;
    memw();
  }
  if (psStack_60[1] < 0) {
    psStack_60[1] = 0;
    memw();
  }
  else if (0x1ff < psStack_60[1]) {
    psStack_60[1] = 0x1ff;
    memw();
  }
  (**(code **)(_DAT_3ffc7e64 + 0xb8))(2,iStack_4c,iVar11);
  (**(code **)(_DAT_3ffc7e64 + 0xb8))(3,iStack_4c,psStack_60[1]);
  return;
}

