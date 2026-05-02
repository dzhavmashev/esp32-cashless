// Function : FUN_4010aaa4
// Address  : 0x4010aaa4
// Size     : 1061 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_4010aaa4(char *param_1,undefined4 *param_2,int param_3,undefined4 param_4,byte param_5)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  uint uStack_3c;
  int iStack_38;
  undefined1 uStack_34;
  
  uVar11 = (uint)param_5;
  if ((param_2 == (undefined4 *)0x0) || (param_1 == (char *)0x0)) {
    uVar5 = 0xf0;
    goto LAB_4010ab10;
  }
  uVar5 = 0xf0;
  if (*param_1 == '\0') goto LAB_4010ab10;
  memw();
  uVar6 = (*(code *)&SUB_4008c01c)(param_1);
  uVar5 = 0xf0;
  if (0xff < uVar6) goto LAB_4010ab10;
  iVar7 = (*(code *)&SUB_4008bdec)(param_1," state:");
  if (iVar7 == 0) {
    if ((param_5 & 0xfd) == 1) {
      param_2[3] = 0x1000000;
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      *(undefined1 *)(param_2 + 4) = 0;
      *(undefined1 *)(param_2 + 5) = 6;
      memw();
    }
    else {
      *(undefined1 *)(param_2 + 5) = 0;
      *param_2 = 0x100007f;
      param_2[3] = 0;
      param_2[2] = 0;
      param_2[1] = 0;
      *(undefined1 *)(param_2 + 4) = 0;
      memw();
      memw();
    }
    goto LAB_4010ab0e;
  }
  iVar7 = FUN_4010af14(param_1,param_2);
  if (iVar7 == 0) {
LAB_4010ab48:
    cVar3 = FUN_4010a484(param_1,param_2,uVar11);
    if ((cVar3 != '\0') &&
       ((1 < (uVar11 - 2 & 0xff) ||
        (cVar3 = FUN_4010a484(param_1,param_2,uVar11 - 2 == 0), cVar3 != '\0')))) {
      pcVar8 = (char *)(*(code *)&SUB_4008ca5c)(param_1,"calhost");
      if (pcVar8 != param_1 + (uVar6 - 6)) {
        iVar7 = 0;
        piVar10 = (int *)&DAT_3ffc5cd8;
        do {
          if ((char)piVar10[5] == '\x06') {
            bVar1 = true;
            if (((*piVar10 == 0) && (piVar10[1] == 0)) && (piVar10[2] == 0)) {
              bVar1 = piVar10[3] != 0;
            }
          }
          else {
            bVar1 = *piVar10 != 0;
          }
          if (bVar1) {
            uStack_34 = 0;
            memw();
            goto LAB_4010ab82;
          }
          iVar7 = iVar7 + 1;
          piVar10 = piVar10 + 6;
        } while (iVar7 != 3);
        uVar5 = 0xfa;
        goto LAB_4010ab10;
      }
      uStack_34 = 1;
LAB_4010ab82:
      iVar7 = 0x3ffc5d50;
      iVar12 = 0x3ffc5d50;
      cVar3 = '\0';
      do {
        cVar2 = cVar3;
        if (*(char *)(iVar7 + 0x1e) == '\x02') {
          memw();
          iVar9 = FUN_4018529c(param_1,iVar7 + 0x24,0x100);
          if (((iVar9 == 0) && (*(byte *)(iVar7 + 0x124) == uVar11)) && (_DAT_3ffc5d20 == 0)) {
            uVar5 = 0xfb;
            memw();
            memw();
            _DAT_3ffc5d20 = param_3;
            _DAT_3ffc5d24 = param_4;
            DAT_3ffc5d28 = cVar2;
            bRam3ffc5d29 = param_5;
            goto LAB_4010ab10;
          }
        }
        iVar7 = iVar7 + 0x128;
        cVar3 = cVar2 + '\x01';
      } while ((char)(cVar2 + '\x01') != '\x04');
      uVar5 = rsr(0xd4);
      wsr(0xbc,uVar5);
      wsr(0xd4,0x4010ad98);
      isync();
      rsr(cVar2);
      if (DAT_3ffc5d6e == '\0') {
        iStack_38 = 0;
      }
      else {
        iStack_38 = 4;
        if ((DAT_3ffc5d6e == '\x03') && (DAT_3ffc61f0 != DAT_3ffc5d72)) {
          iStack_38 = 0;
        }
        uVar5 = 0xff;
        if ((iStack_38 == 4) ||
           (iVar12 = iStack_38 * 0x128 + 0x3ffc5d50, (&DAT_3ffc5d6e)[iStack_38 * 0x128] != '\x03'))
        goto LAB_4010ab10;
        memw();
      }
      uVar5 = rsr(0x12);
      wsr(0xfa,uVar5);
      wsr(0x12,0x4010adc9);
      isync();
      rsr(3);
      if (_DAT_3ffc5d20 == 0) {
        DAT_3ffc5d28 = (char)iStack_38;
        *(char *)(iVar12 + 0x22) = DAT_3ffc61f0;
        *(undefined1 *)(iVar12 + 0x1e) = 1;
        *(byte *)(iVar12 + 0x124) = param_5;
        memw();
        memw();
        memw();
        _DAT_3ffc5d20 = param_3;
        _DAT_3ffc5d24 = param_4;
        bRam3ffc5d29 = param_5;
        (*(code *)&SUB_4008b3d0)(iVar12 + 0x24,param_1,uVar6);
        *(undefined1 *)(iVar12 + uVar6 + 0x24) = 0;
        memw();
        uStack_3c = 0;
        if (_DAT_3ffc61f4 == 0) {
          iVar7 = FUN_40113f54(0x2e);
          if (iVar7 == 0) {
            _DAT_3ffc61f4 = 0;
            memw();
            goto LAB_4010ac7f;
          }
          do {
            do {
              uVar4 = (*(code *)&SUB_400842fc)();
            } while (uVar4 < 0x400);
            cVar3 = FUN_40113770(iVar7,&DAT_3f40fba4,uVar4);
          } while (cVar3 == -8);
          if (cVar3 != '\0') {
            FUN_40113ef0(iVar7);
            _DAT_3ffc61f4 = 0;
            memw();
            goto LAB_4010ac7f;
          }
          (*(code *)&LAB_401853ff_1)(iVar7,0x4010a524);
          memw();
          DAT_3ffc61f1 = 0;
          _DAT_3ffc61f4 = iVar7;
        }
        else {
LAB_4010ac7f:
          iVar7 = 4;
          uStack_3c = (uint)DAT_3ffc61f1;
          do {
            uStack_3c = uStack_3c + 1 & 0xff;
            if (3 < uStack_3c) {
              uStack_3c = 0;
            }
            if (*(int *)(&DAT_3ffc61f4 + uStack_3c * 4) != 0) {
              memw();
              memw();
              DAT_3ffc61f1 = (byte)uStack_3c;
              goto LAB_4010ae2d;
            }
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          uStack_3c = 4;
        }
LAB_4010ae2d:
        *(char *)(iVar12 + 0x23) = (char)uStack_3c;
        memw();
        if (uStack_3c != 4) {
          *(undefined1 *)(iVar12 + 0x125) = uStack_34;
          memw();
          DAT_3ffc61f0 = DAT_3ffc61f0 + '\x01';
          memw();
          memw();
          FUN_4010a2c4(iStack_38);
          uVar5 = 0xfb;
          if (DAT_3ffc6204 == '\0') {
            uVar5 = 0xfb;
            FUN_40113258(1000,0x4010aa94);
            DAT_3ffc6204 = '\x01';
            memw();
            memw();
          }
          goto LAB_4010ab10;
        }
        *(undefined1 *)(iVar12 + 0x1e) = 0;
        memw();
        _DAT_3ffc5d20 = 0;
        memw();
      }
      uVar5 = 0xff;
      goto LAB_4010ab10;
    }
  }
  else if (*(char *)(param_2 + 5) == '\x06') {
    if (uVar11 == 0) goto LAB_4010ab48;
  }
  else if ((*(char *)(param_2 + 5) != '\0') || (uVar11 == 1)) goto LAB_4010ab48;
LAB_4010ab0e:
  uVar5 = 0;
LAB_4010ab10:
  memw();
  return uVar5;
}

