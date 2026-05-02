// Function : FUN_400ea068
// Address  : 0x400ea068
// Size     : 2374 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ea068(uint *param_1,int param_2,undefined2 param_3,undefined4 *****param_4,uint param_5,
                 int param_6,char param_7,int param_8,uint *param_9,uint param_10,uint *param_11,
                 char param_12,int param_13)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  byte bVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  byte bVar16;
  char *pcVar17;
  undefined4 uVar18;
  undefined8 uVar19;
  uint uStack_274;
  undefined4 ****ppppuStack_270;
  undefined4 uStack_250;
  uint *puStack_24c;
  undefined4 uStack_248;
  uint local_244 [4];
  undefined1 uStack_234;
  undefined1 uStack_233;
  undefined2 uStack_232;
  undefined4 uStack_230;
  undefined4 ****appppuStack_224 [3];
  byte bStack_215;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_274 = param_10;
  uStack_250 = 1;
  ppppuStack_270 = param_4;
  if (((param_10 == 0 && param_6 == 0) && (param_12 == '\0' && param_11 == (uint *)0x0)) &&
     (param_7 == '\0')) goto LAB_400ea0c0;
  *param_1 = 0xffffffff;
  uVar13 = FUN_401095ac(2,1,6);
  *param_1 = uVar13;
  if ((int)uVar13 < 0) {
    uVar19 = func_0x40085c04();
    param_11 = (uint *)((ulonglong)uVar19 >> 0x20);
    uVar5 = FUN_401847ec("_attach");
    uVar7 = (*(code *)&SUB_4000cff8)((int)uVar19,param_11,1000,0);
    FUN_4012105c("d) %s\r\n",uVar7,uVar5,0x49,"e_error");
    goto LAB_400ea116;
  }
  uVar10 = FUN_4011fc40(uVar13,3,0);
  FUN_4011fc40(uVar13,4,uVar10 | 0x4000);
  func_0x4008b538(&uStack_234,0,0x10);
  uStack_233 = 2;
  uStack_230 = *(undefined4 *)(param_2 + 4);
  uStack_232 = FUN_40185288(param_3);
  if ((int)param_5 < 1) {
    param_5 = 30000;
  }
  param_1[0x224] = param_5;
  local_244[0]._0_1_ = 0;
  uVar13 = *param_1;
  if (uVar13 < 0x40) {
    local_244[uVar13 >> 5] = 1 << 0x20 - (0x20 - (uVar13 & 0x1f)) | local_244[uVar13 >> 5];
  }
  local_244[2] = param_5 / 1000;
  local_244[3] = (param_5 % 1000) * 1000;
  iVar4 = FUN_401091ec(uVar13,&uStack_234,0x10);
  if (-1 < iVar4) goto LAB_400ea27e;
  piVar3 = (int *)FUN_40173a84();
  if (*piVar3 == 0x77) goto LAB_400ea27e;
  uVar19 = func_0x40085c04();
  uVar5 = FUN_401847ec("_attach");
  uVar13 = *param_1;
  puVar6 = (undefined4 *)FUN_40173a84();
  param_11 = (uint *)*puVar6;
  puVar6 = (undefined4 *)FUN_40173a84();
  uVar7 = FUN_401745c8(*puVar6);
  uVar8 = (*(code *)&SUB_4000cff8)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),1000,0);
  pcVar17 = "ocket\r\n";
  uVar18 = 99;
LAB_400ea24e:
  FUN_4012105c(pcVar17,uVar8,uVar5,uVar18,"e_error",uVar13,param_11,uVar7);
  uVar13 = *param_1;
  do {
    FUN_401090b4(uVar13);
    *param_1 = 0xffffffff;
    param_1 = (uint *)0xffffffff;
    while( true ) {
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      func_0x40082ecc();
LAB_400ea27e:
      iVar4 = FUN_400fefb4(*param_1 + 1,0,local_244,0,local_244 + 2);
      if (iVar4 < 0) {
        uVar19 = func_0x40085c04();
        uVar5 = FUN_401847ec("_attach");
        uVar13 = *param_1;
        puVar6 = (undefined4 *)FUN_40173a84();
        param_11 = (uint *)*puVar6;
        puVar6 = (undefined4 *)FUN_40173a84();
        uVar7 = FUN_401745c8(*puVar6);
        uVar8 = (*(code *)&SUB_4000cff8)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),1000,0);
        uVar18 = 0x6b;
        pcVar17 = " \"%s\"\r\n";
        goto LAB_400ea24e;
      }
      uVar13 = *param_1;
      if (iVar4 == 0) break;
      uStack_248 = 4;
      iVar4 = FUN_401099c4(uVar13,0xfff,0x1007,&puStack_24c,&uStack_248);
      if (iVar4 < 0) {
        uVar19 = func_0x40085c04();
        uVar5 = FUN_401847ec("_attach");
        puVar14 = (uint *)*param_1;
        puVar6 = (undefined4 *)FUN_40173a84();
        param_11 = (uint *)*puVar6;
        puVar6 = (undefined4 *)FUN_40173a84();
        uVar7 = FUN_401745c8(*puVar6);
        uVar8 = (*(code *)&SUB_4000cff8)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),1000,0);
        pcVar17 = " \"%s\"\r\n";
        uVar18 = 0x7a;
        puVar9 = param_11;
LAB_400ea37e:
        FUN_4012105c(pcVar17,uVar8,uVar5,uVar18,"e_error",puVar14,puVar9,uVar7);
        FUN_401090b4(*param_1);
        *param_1 = 0xffffffff;
LAB_400ea0c0:
        param_1 = (uint *)0xffffffff;
      }
      else {
        if (puStack_24c != (uint *)0x0) {
          uVar19 = func_0x40085c04();
          uVar5 = FUN_401847ec("_attach");
          puVar9 = puStack_24c;
          param_11 = (uint *)*param_1;
          uVar7 = FUN_401745c8(puStack_24c);
          uVar8 = (*(code *)&SUB_4000cff8)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),1000,0);
          uVar18 = 0x81;
          pcVar17 = " \"%s\"\r\n";
          puVar14 = param_11;
          goto LAB_400ea37e;
        }
        iVar4 = FUN_40109a64(*param_1,0xfff,0x1006,local_244 + 2,8);
        if (iVar4 < 0) {
          uVar19 = func_0x40085c04();
          param_11 = (uint *)((ulonglong)uVar19 >> 0x20);
          uVar5 = FUN_401847ec("_attach");
          uVar7 = (*(code *)&SUB_4000cff8)((int)uVar19,param_11,1000,0);
          pcVar17 = " \"%s\"\r\n";
          uVar8 = 0x8a;
LAB_400ea437:
          FUN_4012105c(pcVar17,uVar7,uVar5,uVar8,"e_error");
          goto LAB_400ea0c0;
        }
        iVar4 = FUN_40109a64(*param_1,0xfff,0x1005,local_244 + 2,8);
        if (iVar4 < 0) {
          uVar19 = func_0x40085c04();
          param_11 = (uint *)((ulonglong)uVar19 >> 0x20);
          uVar5 = FUN_401847ec("_attach");
          uVar7 = (*(code *)&SUB_4000cff8)((int)uVar19,param_11,1000,0);
          uVar8 = 0x8b;
          pcVar17 = "iled.\r\n";
          goto LAB_400ea437;
        }
        iVar4 = FUN_40109a64(*param_1,6,1,&uStack_250,4);
        if (iVar4 < 0) {
          uVar19 = func_0x40085c04();
          param_11 = (uint *)((ulonglong)uVar19 >> 0x20);
          uVar5 = FUN_401847ec("_attach");
          uVar7 = (*(code *)&SUB_4000cff8)((int)uVar19,param_11,1000,0);
          uVar8 = 0x8d;
          pcVar17 = "iled.\r\n";
          goto LAB_400ea437;
        }
        iVar4 = FUN_40109a64(*param_1,0xfff,8,&uStack_250,4);
        if (iVar4 < 0) {
          uVar19 = func_0x40085c04();
          param_11 = (uint *)((ulonglong)uVar19 >> 0x20);
          uVar5 = FUN_401847ec("_attach");
          uVar7 = (*(code *)&SUB_4000cff8)((int)uVar19,param_11,1000,0);
          uVar8 = 0x8e;
          pcVar17 = "iled.\r\n";
          goto LAB_400ea437;
        }
        FUN_40137f54(param_1 + 0xd8);
        uVar5 = _DAT_3ffbdb98;
        uVar7 = func_0x4008c024(_DAT_3ffbdb98);
        puVar9 = (uint *)FUN_40133dcc(param_1 + 0xc4,0x40137fd4,param_1 + 0xd8,uVar5,uVar7);
        uVar5 = 0x98;
        if ((int)puVar9 < 0) {
LAB_400ea668:
          param_1 = (uint *)FUN_400e9fc8(puVar9,"e_error",uVar5);
        }
        else {
          puVar14 = param_1 + 0x8a;
          uVar19 = FUN_4012cfd8(puVar14,0,0,0);
          uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
          puVar9 = (uint *)uVar19;
          uVar5 = 0xa1;
          if (puVar9 != (uint *)0x0) goto LAB_400ea668;
          if (param_13 != 0) {
            uVar19 = FUN_4012c908(puVar14,param_13,0xa1);
            uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
            puVar9 = (uint *)uVar19;
            uVar5 = 0xa7;
            if (puVar9 != (uint *)0x0) goto LAB_400ea668;
          }
          if (param_12 == '\0') {
            if (param_6 != 0) {
              puVar9 = param_1 + 0x176;
              FUN_4014471c(puVar9);
              (*(code *)&LAB_4018594b_1)(puVar14,2);
              iVar4 = func_0x4008c024(param_6);
              param_11 = (uint *)FUN_4014517c(puVar9,param_6,iVar4 + 1);
              (*(code *)&LAB_4018598b_1)(puVar14,puVar9,0);
              if (-1 < (int)param_11) goto LAB_400ea59e;
              FUN_40144730(puVar9);
              uVar5 = 0xbb;
              puVar9 = param_11;
              goto LAB_400ea668;
            }
            if (param_7 != '\0') {
              puVar9 = (uint *)FUN_400e9f60(puVar14);
              uVar5 = 0xc2;
              if (-1 < (int)puVar9) goto LAB_400ea59e;
              goto LAB_400ea668;
            }
            if ((uStack_274 != 0) && (param_11 != (uint *)0x0)) {
              uVar13 = func_0x4008c024(param_11,uVar7,uVar5);
              if ((0x40 < uVar13) || (puVar9 = param_11, (uVar13 & 1) != 0)) {
                uVar19 = func_0x40085c04();
                param_11 = (uint *)((ulonglong)uVar19 >> 0x20);
                uVar5 = FUN_401847ec("_attach");
                uVar7 = (*(code *)&SUB_4000cff8)((int)uVar19,param_11,1000,0);
                uVar8 = 200;
                pcVar17 = "iled.\r\n";
                goto LAB_400ea437;
              }
              while( true ) {
                uVar10 = func_0x4008c024(param_11);
                if (uVar10 <= (uint)((int)puVar9 - (int)param_11)) break;
                cVar1 = (char)*puVar9;
                bVar12 = cVar1 - 0x30;
                if (9 < bVar12) {
                  if ((byte)(cVar1 + 0xbfU) < 6) {
                    bVar12 = cVar1 - 0x37;
                  }
                  else {
                    if (5 < (byte)(cVar1 + 0x9fU)) goto LAB_400ea0c0;
                    bVar12 = cVar1 + 0xa9;
                  }
                }
                iVar4 = (int)puVar9 - (int)param_11 >> 1;
                cVar1 = *(char *)((int)puVar9 + 1);
                *(byte *)((int)appppuStack_224 + iVar4) = bVar12 << 4;
                bVar16 = cVar1 - 0x30;
                if (9 < bVar16) {
                  if ((byte)(cVar1 + 0xbfU) < 6) {
                    bVar16 = cVar1 - 0x37;
                  }
                  else {
                    if (5 < (byte)(cVar1 + 0x9fU)) goto LAB_400ea0c0;
                    bVar16 = cVar1 + 0xa9;
                  }
                }
                *(byte *)((int)appppuStack_224 + iVar4) = bVar12 << 4 | bVar16;
                puVar9 = (uint *)((int)puVar9 + 2);
              }
              uVar5 = func_0x4008c024(uStack_274);
              puVar9 = (uint *)FUN_4012c7a8(puVar14,appppuStack_224,uVar13 >> 1,uStack_274,uVar5);
              if (puVar9 == (uint *)0x0) goto LAB_400ea59e;
              uVar19 = func_0x40085c04();
              uVar5 = FUN_401847ec("_attach");
              uVar7 = (*(code *)&SUB_4000cff8)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),1000,0);
              FUN_4012105c(" long\r\n",uVar7,uVar5,0xdf,"e_error",puVar9);
              uVar5 = 0xe0;
              goto LAB_400ea668;
            }
            goto LAB_400ea0c0;
          }
          (*(code *)&LAB_4018594b_1)(puVar14,0);
LAB_400ea59e:
          uStack_274 = (uint)(param_8 != 0 && param_9 != (uint *)0x0);
          if ((param_12 != '\x01') && (uStack_274 != 0)) {
            param_11 = param_1 + 0x1cc;
            FUN_4014471c(param_11);
            puVar15 = param_1 + 0x222;
            (*(code *)&LAB_401864d3_1)(puVar15);
            iVar4 = func_0x4008c024(param_8);
            puVar9 = (uint *)FUN_4014517c(param_11,param_8,iVar4 + 1);
            if ((int)puVar9 < 0) {
              FUN_40144730(param_11);
              uVar5 = 0xf0;
            }
            else {
              iVar4 = func_0x4008c024(param_9);
              puVar9 = (uint *)FUN_4013aacc(puVar15,param_9,iVar4 + 1,0,0);
              if (puVar9 == (uint *)0x0) {
                FUN_4012c790(puVar14,param_11,puVar15);
                goto LAB_400ea840;
              }
              FUN_40144730(param_11);
              uVar5 = 0xf8;
            }
            goto LAB_400ea668;
          }
LAB_400ea840:
          bVar2 = false;
          param_11 = param_1 + 2;
          if ((undefined4 *****)ppppuStack_270 == (undefined4 *****)0x0) {
            FUN_400f0598(appppuStack_224,param_2);
            ppppuStack_270 = appppuStack_224;
            bVar2 = true;
            if ((bStack_215 & 0x80) == 0) {
              ppppuStack_270 = appppuStack_224[0];
              bVar2 = true;
            }
          }
          puVar9 = (uint *)FUN_4012c88c(param_11,ppppuStack_270);
          if (bVar2) {
            FUN_400f0a50(appppuStack_224);
          }
          uVar5 = 0x102;
          if (puVar9 != (uint *)0x0) goto LAB_400ea668;
          (*(code *)&LAB_4018596a_2)(puVar14,0x40133f60,param_1 + 0xc4);
          puVar9 = (uint *)FUN_4012ccb4(param_11,puVar14);
          if (puVar9 != (uint *)0x0) {
            uVar5 = 0x108;
            goto LAB_400ea668;
          }
          (*(code *)&LAB_4018597a_2)(param_11,param_1,0x4012d74c,0x4012d6f8,0);
          iVar4 = FUN_400f1a9c();
          while (puVar9 = (uint *)FUN_4012c9dc(param_11), puVar9 != (uint *)0x0) {
            if (((uint)puVar9 & 0xffffff7f) != 0xffff9700) {
              uVar5 = 0x111;
              goto LAB_400ea668;
            }
            iVar11 = FUN_400f1a9c();
            if (param_1[0x225] < (uint)(iVar11 - iVar4)) goto LAB_400ea0c0;
            func_0x4009183c(2);
          }
          if (uStack_274 != 0) {
            puVar9 = (uint *)FUN_40129ce0(param_11);
          }
          iVar4 = (*(code *)&LAB_4018599a_2)(param_11);
          if (iVar4 != 0) {
            func_0x4008b538(appppuStack_224,0,0x200);
            FUN_40144108(appppuStack_224,0x200,"ed %d\r\n",iVar4);
            uVar19 = func_0x40085c04();
            param_11 = (uint *)((ulonglong)uVar19 >> 0x20);
            uVar5 = FUN_401847ec("_attach");
            uVar7 = (*(code *)&SUB_4000cff8)((int)uVar19,param_11,1000,0);
            FUN_4012105c("\r\n",uVar7,uVar5,0x127,"e_error",appppuStack_224);
            uVar5 = 0x128;
            goto LAB_400ea668;
          }
          if (param_6 != 0) {
            FUN_40144730(param_1 + 0x176);
          }
          if (param_8 != 0) {
            FUN_40144730(param_1 + 0x1cc);
          }
          param_11 = param_9;
          if (param_9 != (uint *)0x0) {
            FUN_40139b44(param_1 + 0x222);
          }
LAB_400ea116:
          param_1 = (uint *)*param_1;
        }
      }
    }
  } while( true );
}

