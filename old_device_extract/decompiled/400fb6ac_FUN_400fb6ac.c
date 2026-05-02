// Function : FUN_400fb6ac
// Address  : 0x400fb6ac
// Size     : 469 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fb6ac(int param_1,byte param_2,uint param_3,int param_4,uint *param_5,byte *param_6,
                 byte param_7,byte param_8)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uStack_60;
  uint uStack_58;
  uint uStack_54;
  int iStack_48;
  undefined1 auStack_44 [32];
  uint uStack_24;
  
  param_3 = param_3 & 0xff;
  memw();
  iVar6 = *(int *)(param_1 + 0xc);
  memw();
  uStack_24 = _DAT_3ffc5708;
  bVar1 = iVar6 == -0x10;
  bVar2 = iVar6 == 0;
  if (((!bVar1 && !bVar2) &&
      (bVar4 = iVar6 == -1 || (bVar1 || bVar2), iVar6 != -1 && (!bVar1 && !bVar2))) &&
     (uVar5 = *param_5, uVar5 < 0x7e)) {
    uVar7 = *(uint *)(param_1 + 0x3c);
    uVar5 = (uVar5 < uVar7) * uVar7 + (uVar5 >= uVar7) * uVar5;
    uVar7 = *(uint *)(param_1 + 0x38);
    uStack_58 = (uVar7 < 0x7e) * uVar7 + (uint)(uVar7 >= 0x7e) * 0x7e;
    if ((bVar4 || param_3 != 0xff && param_4 != 0) && (param_2 != 0xff || bVar4)) {
      memw();
      FUN_400fb060(auStack_44,param_2,param_3,0,param_4,param_7);
      uVar5 = FUN_400faf84(param_1 + 0x44,uVar5,auStack_44);
      if (0x7d < uVar5) goto LAB_400fb6fc;
    }
    uStack_54 = (uint)(param_4 == 0);
    goto LAB_400fb75e;
  }
LAB_400fb6fc:
  memw();
  iVar6 = 0x1102;
LAB_400fb798:
  do {
    param_1 = iVar6;
    param_3 = uStack_24;
    uVar7 = _DAT_3ffc5708;
    memw();
    memw();
    if (uStack_24 == _DAT_3ffc5708) {
      return;
    }
    memw();
    (*(code *)&SUB_40082ec4)();
    iVar6 = param_1;
    do {
      iVar3 = FUN_400fc574(param_6);
      if (iVar3 == *(int *)(param_6 + 4)) {
        uVar8 = (uint)param_6[1];
        memw();
        iVar3 = FUN_40184a1c(uVar8);
        if (iVar3 != 0) {
          uStack_60 = param_6[2] + uVar7;
        }
        uVar5 = uStack_60;
        if ((param_2 == 0xff) || (*param_6 == param_2)) {
          if (param_4 != 0) {
            memw();
            iVar3 = (*(code *)&SUB_4008c080)(param_4,param_6 + 8,0xf);
            if (iVar3 != 0) goto LAB_400fb75e;
          }
          if ((param_7 == 0xff) || (param_3 != 0x42)) {
            if (param_3 == 0x48) {
              if ((param_6[3] != 0xff) || ((param_8 != 0xff && (param_6[0x1d] != param_8))))
              goto LAB_400fb75e;
            }
            else if (param_3 == 0xff) goto LAB_400fb878;
            if (param_3 == uVar8) goto LAB_400fb878;
            if (((param_2 & param_7) != 0xff) || (uStack_54 == 0)) goto LAB_400fb868;
          }
          else if (param_6[3] == param_7) {
            if (uVar8 == 0x42) {
LAB_400fb878:
              *param_5 = uVar7;
              memw();
            }
            else {
LAB_400fb868:
              *param_5 = uVar7;
              memw();
              iVar6 = 0x1103;
            }
            goto LAB_400fb798;
          }
        }
      }
      else {
        iVar6 = FUN_400fb554(param_1,uVar7);
        uVar5 = uStack_60;
        if (iVar6 != 0) break;
      }
LAB_400fb75e:
      do {
        uVar7 = uVar5;
        if (uStack_58 <= uVar7) goto LAB_400fb6fc;
        uStack_60 = uVar7 + 1;
        memw();
        iVar6 = (*(code *)&LAB_40184b76_2)(param_1 + 0x18,uVar7,&iStack_48);
        if (iVar6 != 0) goto LAB_400fb798;
        uVar5 = uStack_60;
      } while (iStack_48 != 2);
      iVar6 = FUN_40184b50(param_1,uVar7,param_6);
    } while (iVar6 == 0);
    *(undefined4 *)(param_1 + 0xc) = 0;
  } while( true );
}

