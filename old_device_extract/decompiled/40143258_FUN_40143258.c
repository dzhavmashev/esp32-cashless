// Function : FUN_40143258
// Address  : 0x40143258
// Size     : 721 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40143258(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined1 *param_6,undefined4 param_7,undefined1 *param_8,undefined1 *param_9)

{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 uStack_100;
  undefined1 *puStack_fc;
  int iStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined1 auStack_ec [4];
  int iStack_e8;
  undefined4 uStack_e4;
  undefined1 auStack_e0 [12];
  int iStack_d4;
  int iStack_d0;
  undefined1 *puStack_cc;
  undefined1 *puStack_c8;
  undefined1 *puStack_c4;
  undefined4 uStack_c0;
  undefined1 *puStack_b8;
  undefined1 *puStack_b4;
  undefined1 auStack_b0 [12];
  undefined1 auStack_a4 [32];
  undefined1 auStack_84 [32];
  undefined1 auStack_64 [64];
  int iStack_24;
  undefined1 auStack_20 [32];
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_100 = 0;
  iStack_f8 = param_1[2];
  puStack_fc = (undefined1 *)0x0;
  puVar7 = (undefined1 *)(iStack_f8 + param_1[1]);
  uStack_f4 = 4;
  puVar8 = &DAT_00000004;
  iVar3 = -0x2f62;
  if (*param_1 != 0x30) goto LAB_401432c8;
  memw();
  iVar3 = FUN_401419c8(&iStack_f8,puVar7,auStack_ec,&iStack_d4);
  puVar8 = &DAT_00000004;
  if (iVar3 == 0) {
    iVar3 = 0x30;
    if (iStack_e8 == 9) goto LAB_401432e4;
    goto LAB_401432c5;
  }
LAB_401432b4:
  iVar3 = iVar3 + -0x2f00;
LAB_401432c8:
  param_2 = _DAT_3ffc5708;
  memw();
  memw();
  if (iStack_24 == _DAT_3ffc5708) {
    return;
  }
  (*(code *)&SUB_40082ec4)();
LAB_401432e4:
  iVar4 = (*(code *)&SUB_4008b33c)(&DAT_3f4230c0,uStack_e4);
  if (iVar4 == 0) goto code_r0x401432f3;
  goto LAB_401432c5;
code_r0x401432f3:
  puStack_c8 = puStack_cc;
  puVar6 = puStack_cc + iStack_d0;
  bVar1 = iStack_d4 != iVar3;
  iVar3 = -0x2f62;
  if (bVar1) goto LAB_401432c8;
  memw();
  iVar3 = FUN_40141738(&puStack_c8,puVar6,&puStack_b8,puVar8);
  puVar2 = puStack_b8;
  puVar8 = auStack_20;
  if (iVar3 == 0) {
    puStack_b4 = puStack_c8;
    puStack_c8 = puStack_c8 + (int)puStack_b8;
    memw();
    iVar3 = FUN_4014180c(&puStack_c8,puVar6,&uStack_100);
    puVar8 = puVar2;
    if (iVar3 != 0) goto LAB_40143324;
    puVar8 = puStack_c8;
    if (puVar6 != puStack_c8) {
      puVar8 = auStack_20;
      iVar3 = FUN_4014180c(&puStack_c8,puVar6,&puStack_fc);
      if ((iVar3 != 0) &&
         (puVar8 = (undefined1 *)(uint)(iVar3 != -0x62), puVar8 != (undefined1 *)0x0))
      goto LAB_40143324;
      if (puVar6 != puStack_c8) {
        iVar3 = FUN_40141a58(&puStack_c8,puVar6,auStack_b0);
        if (iVar3 != 0) goto LAB_40143324;
        puVar8 = auStack_20;
        iVar4 = FUN_40139608(auStack_b0,&uStack_f4);
        iVar3 = -0x2e80;
        if ((iVar4 != 0) || (iVar3 = -0x2f66, puVar6 != puStack_c8)) goto LAB_401432c8;
      }
    }
  }
  else {
LAB_40143324:
    iVar3 = iVar3 + -0x2f00;
    if (iVar3 != 0) goto LAB_401432c8;
  }
  iVar4 = FUN_40138f28(uStack_f4);
  if (iVar4 == 0) {
LAB_401432c5:
    iVar3 = -0x2e80;
    goto LAB_401432c8;
  }
  iVar3 = FUN_401419c8(&iStack_f8,puVar7,auStack_e0,&puStack_c8);
  if (iVar3 != 0) goto LAB_401432b4;
  puVar7 = auStack_20;
  iVar3 = FUN_4013956c(auStack_e0,&uStack_f0);
  if ((iVar3 != 0) || (iVar5 = FUN_40132c44(uStack_f0), iVar5 == 0)) goto LAB_401432c5;
  puStack_fc = (undefined1 *)(*(uint *)(iVar5 + 8) >> 3);
  iVar3 = -0x2f00;
  puVar7 = puStack_c8;
  if ((puStack_c8 != &DAT_00000004) ||
     (puVar7 = *(undefined1 **)(iVar5 + 0x10), puVar8 = puStack_c4, puStack_c4 != puVar7))
  goto LAB_401432c8;
  puVar6 = param_6;
  if (param_2 != 0) {
    if (param_2 != 1) goto LAB_4014343c;
    puVar7 = param_6 + (*(uint *)(iVar5 + 0x18) - (uint)param_6 % *(uint *)(iVar5 + 0x18));
    puVar6 = puVar7;
  }
  iVar3 = -0x6c;
  puVar8 = param_8;
  if (param_8 < puVar6) goto LAB_401432c8;
LAB_4014343c:
  memw();
  FUN_40138f64(auStack_b0);
  FUN_40132c84(auStack_64);
  (*(code *)&SUB_4008b3d0)(auStack_84,uStack_c0,puStack_c4);
  iVar3 = FUN_4013905c(auStack_b0,iVar4,1);
  puVar6 = puStack_fc;
  if (iVar3 == 0) {
    memw();
    iVar3 = FUN_401430dc(auStack_b0,param_3,param_4,puStack_b4,puStack_b8,uStack_100,puStack_fc,
                         auStack_a4);
    puVar7 = puVar6;
    if ((((iVar3 == 0) && (iVar3 = FUN_40133068(auStack_64,iVar5), iVar3 == 0)) &&
        (iVar3 = FUN_40132cb4(auStack_64,auStack_a4,(int)puStack_fc << 3,param_2), iVar3 == 0)) &&
       (iVar3 = FUN_40132fe8(auStack_64), iVar3 == 0)) {
      memw();
      iVar4 = FUN_4013309c(auStack_64,auStack_84,puStack_c4,param_5,param_6,param_7,param_9);
      iVar3 = 0;
      puVar8 = param_9;
      if (iVar4 != 0) {
        iVar3 = -0x2e00;
      }
    }
  }
  memw();
  FUN_40138f78(auStack_b0);
  FUN_40132c98(auStack_64);
  goto LAB_401432c8;
}

