// Function : FUN_401280e0
// Address  : 0x401280e0
// Size     : 1010 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401280e0(int *param_1,undefined2 *param_2,undefined2 *param_3,undefined4 *param_4,
                 uint *param_5,undefined4 param_6,int param_7)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 extraout_a3;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined1 uStack_67;
  undefined1 auStack_66 [66];
  undefined2 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  if (1 < (int)param_3) goto LAB_4012811b;
LAB_401280fa:
  do {
    piVar1 = (int *)0x1;
    while( true ) {
      do {
        param_1 = piVar1;
        param_3 = puStack_24;
        param_2 = _DAT_3ffc5708;
        memw();
        memw();
        if (puStack_24 == _DAT_3ffc5708) {
          return;
        }
        memw();
        (*(code *)&SUB_40082ec4)();
        param_6 = extraout_a3;
LAB_4012811b:
        piVar1 = (int *)FUN_40128094(param_1,param_6,*param_2);
      } while (piVar1 != (int *)0x0);
      puVar9 = param_2 + 1;
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0;
      }
      if (param_5 != (uint *)0x0) {
        *param_5 = 0;
      }
      iVar5 = (int)param_2 + (int)param_3;
      iVar10 = param_1[0x12];
      if (param_7 == 0) {
        iVar11 = 2;
        if (*(int *)(iVar10 + 0x40) != 0) {
          iVar11 = 3;
        }
        puVar8 = (undefined2 *)(iVar11 * *(int *)(iVar10 + 0x44));
        if ((puVar8 < param_3 + -1) &&
           (uVar6 = iVar5 - (int)((int)puVar9 + (int)puVar8), 0x1f < uVar6)) {
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = puVar9;
          }
          if (param_5 != (uint *)0x0) {
            *param_5 = uVar6;
          }
          puVar9 = (undefined2 *)((int)puVar9 + uVar6);
        }
      }
      if (iVar5 - (int)puVar9 < *(int *)(iVar10 + 0x44)) goto LAB_401280fa;
      memw();
      iVar10 = FUN_40128a30(puVar9);
      if (iVar10 == 0) goto LAB_401280fa;
      if ((((*param_1 == 3) && (param_1[0x13] != 0)) &&
          (iVar11 = FUN_40128bf4(param_1[0x13],iVar10), iVar11 == 0)) ||
         ((iVar11 = FUN_40128c14(iVar10), iVar11 != 0 ||
          (iVar11 = FUN_40128c2c(iVar10), iVar11 != 0)))) break;
      memw();
      iVar11 = FUN_40128bf4(iVar10,*(undefined4 *)(param_1[0x12] + 0x50));
      if (-1 < iVar11) break;
      FUN_40128a7c(param_1[0xe],0);
      param_1[0xe] = iVar10;
      iVar10 = param_1[0x12];
      iVar12 = *(int *)(iVar10 + 0x44);
      iVar11 = (int)puVar9 + iVar12;
      if (*(int *)(iVar10 + 0x48) != 0) {
        uStack_67 = 1;
        memw();
        if (iVar12 <= iVar5 - iVar11) {
          memw();
          FUN_40128a7c(*(undefined4 *)(iVar10 + 0x2c),0);
          iVar10 = param_1[0x12];
          uVar2 = FUN_40128a30(iVar11,*(undefined4 *)(iVar10 + 0x44));
          *(undefined4 *)(iVar10 + 0x2c) = uVar2;
          if (*(int *)(param_1[0x12] + 0x2c) != 0) {
            memw();
            iVar10 = FUN_40128a18();
            iVar12 = FUN_40128a30(&uStack_67,1);
            if (((iVar10 != 0) && (iVar12 != 0)) &&
               ((iVar3 = FUN_40128b3c(*(undefined4 *)(param_1[0x12] + 0x4c),iVar12,iVar10),
                iVar3 == 0 &&
                ((iVar3 = FUN_40128c14(*(undefined4 *)(param_1[0x12] + 0x2c)), iVar3 == 0 &&
                 (iVar3 = FUN_40128c2c(*(undefined4 *)(param_1[0x12] + 0x2c)), iVar3 == 0)))))) {
              memw();
              iVar3 = FUN_40128bf4(*(undefined4 *)(param_1[0x12] + 0x2c),iVar10);
              if (iVar3 < 0) {
                FUN_40128a7c(iVar12,0);
                iVar12 = param_1[0x12];
                iVar12 = FUN_40128b08(*(undefined4 *)(iVar12 + 0x2c),*(undefined4 *)(iVar12 + 0x50),
                                      *(undefined4 *)(iVar12 + 0x4c),iVar10);
                if ((iVar12 < 0) || (iVar12 = FUN_40128c2c(iVar10), iVar12 == 0)) break;
                FUN_40128a7c(iVar10,0);
                iVar10 = *(int *)(param_1[0x12] + 0x44);
                goto LAB_401282c7;
              }
            }
            FUN_40128a7c(iVar10,0);
            iVar10 = iVar12;
            break;
          }
        }
        goto LAB_401280fa;
      }
      if ((iVar5 - iVar11 < iVar12 << 1) ||
         (iVar10 = FUN_40128a90(*(undefined4 *)(iVar10 + 0x4c),auStack_66,0x42), iVar10 < 0))
      goto LAB_401280fa;
      iVar12 = param_1[0x12];
      iVar3 = *(int *)(iVar12 + 0x44);
      memw();
      iVar10 = (*(code *)&SUB_4008b33c)(iVar11,auStack_66,iVar3);
      if ((-1 < iVar10) ||
         (iVar10 = (*(code *)&SUB_4008b33c)(iVar11 + iVar3,auStack_66,iVar3), -1 < iVar10))
      goto LAB_401280fa;
      FUN_40128d84(*(undefined4 *)(iVar12 + 0x30),0);
      iVar10 = param_1[0x12];
      uVar2 = FUN_40128dd4(*(undefined4 *)(iVar10 + 0x40),iVar11);
      *(undefined4 *)(iVar10 + 0x30) = uVar2;
      if (*(int *)(param_1[0x12] + 0x30) == 0) goto LAB_401280fa;
      memw();
      iVar10 = FUN_40129004(*(undefined4 *)(param_1[0x12] + 0x40));
      if (iVar10 == 0) goto LAB_401280fa;
      iVar10 = *(int *)(param_1[0x12] + 0x44) << 1;
LAB_401282c7:
      pcVar7 = (char *)(iVar11 + iVar10);
      if ((((iVar5 - (int)pcVar7 < 3) || (*pcVar7 != -1)) ||
          (uVar6 = (uint)(byte)pcVar7[1], uVar6 == 0)) ||
         (((iVar5 - (int)pcVar7) + -1 <= (int)uVar6 || (pcVar7[2] != '!')))) {
        if (*(int *)(param_1[0x12] + 0x5c) == 0) goto LAB_401282f6;
LAB_401284d5:
        piVar1 = (int *)0x7b;
      }
      else {
        if (iVar5 - (int)(pcVar7 + 2) < (int)uVar6) goto LAB_401280fa;
        pcVar7 = pcVar7 + 3;
        uVar6 = uVar6 - 1 & 0xff;
        iVar10 = *(int *)(param_1[0x12] + 0x5c);
        if ((iVar10 != 0) &&
           ((uVar4 = (*(code *)&SUB_4008c01c)(iVar10), uVar6 != uVar4 ||
            (iVar11 = (*(code *)&SUB_4008b33c)(iVar10,pcVar7,uVar6), iVar11 != 0))))
        goto LAB_401284d5;
        (*(code *)&SUB_40094d80)(iVar10);
        iVar11 = param_1[0x12];
        iVar10 = (*(code *)&SUB_40094d60)(uVar6 + 1);
        *(int *)(iVar11 + 0x5c) = iVar10;
        if (iVar10 == 0) goto LAB_401280fa;
        memw();
        (*(code *)&SUB_4008b3d0)(iVar10,pcVar7,uVar6);
        pcVar7 = pcVar7 + uVar6;
        *(undefined1 *)(*(int *)(iVar11 + 0x5c) + uVar6) = 0;
        memw();
        memw();
LAB_401282f6:
        if (param_7 != 0) {
          if ((((2 < iVar5 - (int)pcVar7) && (*pcVar7 == -1)) &&
              (uVar6 = (uint)(byte)pcVar7[1], 1 < uVar6)) &&
             (((int)uVar6 < (iVar5 - (int)pcVar7) + -1 && (pcVar7[2] == '\\')))) {
            if (iVar5 - (int)(pcVar7 + 2) < (int)uVar6) goto LAB_401280fa;
            uVar6 = uVar6 - 1 & 0xff;
            FUN_4010531c(*(undefined4 *)(param_1[0x12] + 0x68));
            iVar10 = param_1[0x12];
            uVar2 = FUN_401052d0(uVar6);
            *(undefined4 *)(iVar10 + 0x68) = uVar2;
            if (*(int *)(param_1[0x12] + 0x68) == 0) goto LAB_401280fa;
            memw();
            FUN_40127178(*(int *)(param_1[0x12] + 0x68),pcVar7 + 3,uVar6);
            pcVar7 = pcVar7 + 3 + uVar6;
          }
          if (((2 < iVar5 - (int)pcVar7) && (*pcVar7 == -1)) &&
             (((byte)pcVar7[1] != 0 &&
              (((int)(uint)(byte)pcVar7[1] < (iVar5 - (int)pcVar7) + -1 && (pcVar7[2] == ']')))))) {
            *param_4 = pcVar7 + 3;
            *param_5 = (byte)pcVar7[1] - 1;
          }
        }
        if (*(int *)(param_1[0x12] + 0x20) != 0) {
          memw();
          iVar5 = FUN_40128bf4(*(int *)(param_1[0x12] + 0x20),param_1[0xe]);
          if ((iVar5 == 0) &&
             ((iVar5 = param_1[0x12], *(int *)(iVar5 + 0x48) == 0 ||
              ((*(int *)(iVar5 + 0x24) != 0 &&
               (iVar5 = FUN_40128bf4(*(int *)(iVar5 + 0x24),*(undefined4 *)(iVar5 + 0x2c)),
               iVar5 == 0)))))) {
            iVar5 = param_1[0x12];
            if (*(int *)(iVar5 + 0x40) == 0) {
              piVar1 = (int *)0xffff;
            }
            else if (*(int *)(iVar5 + 0x28) != 0) {
              iVar5 = FUN_4012907c(*(int *)(iVar5 + 0x40),*(int *)(iVar5 + 0x28),
                                   *(undefined4 *)(iVar5 + 0x30));
              piVar1 = (int *)(-(uint)(iVar5 == 0) & 0xffff);
            }
          }
        }
      }
    }
    FUN_40128a7c(iVar10,0);
  } while( true );
}

