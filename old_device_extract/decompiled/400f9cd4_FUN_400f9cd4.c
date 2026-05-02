// Function : FUN_400f9cd4
// Address  : 0x400f9cd4
// Size     : 559 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f9cd4(undefined1 *param_1,undefined1 param_2,undefined4 param_3,int *param_4,
                 int *param_5,uint param_6)

{
  int *piVar1;
  undefined1 *puVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  char cVar11;
  int in_t0;
  int *piStack_6c;
  int iStack_64;
  int aiStack_44 [6];
  int *piStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_27;
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  uVar4 = *(int *)(param_1 + 0x30) - 1;
  piVar6 = param_4;
  uVar7 = param_6;
  puVar2 = &DAT_0000110e;
  iVar10 = in_t0;
  if (param_5 <= (int *)(((uVar4 < 0x7f) * uVar4 + (uint)(uVar4 >= 0x7f) * 0x7f) * 4000)) {
    piVar6 = (int *)0x0;
    piVar5 = (int *)0x0;
    uVar7 = 0;
    iStack_64 = 0;
    piStack_6c = param_5;
    goto LAB_400f9d1e;
  }
LAB_400f9dc5:
  do {
    do {
      param_1 = puVar2;
      piVar1 = piStack_24;
      piVar5 = _DAT_3ffc5708;
      memw();
      memw();
      if (piStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      in_t0 = iVar10;
LAB_400f9de1:
      puVar2 = (undefined1 *)FUN_400fb4c8(iVar10);
      iVar10 = in_t0;
    } while (puVar2 != (undefined1 *)0x0);
LAB_400f9db9:
    puVar2 = (undefined1 *)FUN_400fc124(param_1 + 0x10);
    iVar10 = in_t0;
    if (puVar2 != (undefined1 *)0x0) goto LAB_400f9dc5;
    piVar3 = (int *)FUN_400fb4e4(*(undefined4 *)(param_1 + 0x14));
    if (piVar1 == piVar3) {
      puVar2 = (undefined1 *)0x1105;
      iVar10 = in_t0;
      goto LAB_400f9dc5;
    }
LAB_400f9d1e:
    iVar10 = *(int *)(param_1 + 0x14);
    memw();
    piVar1 = (int *)FUN_400fb4e4(iVar10);
    if (uVar7 == 0) {
      if (piVar1 < param_5) {
        if (piVar1 < (int *)0x190) goto LAB_400f9db2;
LAB_400f9d3c:
        iVar8 = (uint)(piStack_6c < piVar1) * (int)piStack_6c +
                (uint)(piStack_6c >= piVar1) * (int)piVar1;
        piStack_6c = (int *)((int)piStack_6c - iVar8);
        uVar9 = uVar7 + (param_6 & 0xff);
        uVar4 = uVar7 + 1;
        uVar7 = uVar4 & 0xff;
        memw();
        puVar2 = (undefined1 *)
                 FUN_400fb29c(iVar10,param_2,0x42,param_3,(int)param_4 + iStack_64,iVar8,
                              uVar9 & 0xff);
        if (puVar2 != (undefined1 *)0x0) {
          iVar10 = in_t0;
          if (puVar2 != (undefined1 *)0x110a) goto LAB_400f9d7d;
          goto LAB_400f9dc5;
        }
        memw();
        piVar3 = (int *)(*(code *)&SUB_40094d60)(0xc);
        if (piVar3 == (int *)0x0) {
          puVar2 = (undefined1 *)0x101;
          goto LAB_400f9d7d;
        }
        *piVar3 = 0;
        piVar3[1] = 0;
        piVar3[2] = iVar10;
        if (piVar6 != (int *)0x0) {
          piVar6[1] = (int)piVar3;
        }
        *piVar3 = (int)piVar6;
        piVar3[1] = 0;
        if (piVar5 == (int *)0x0) {
          piVar5 = piVar3;
        }
        if ((piStack_6c != (int *)0x0) || ((uint)((int)piVar1 - iVar8) < 0x20)) {
          if (*(int *)(iVar10 + 0xc) != -4) {
            memw();
            puVar2 = (undefined1 *)FUN_400fb4c8(iVar10);
            if (puVar2 != (undefined1 *)0x0) goto LAB_400f9d7d;
          }
          memw();
          puVar2 = (undefined1 *)FUN_400fc124(param_1 + 0x10);
          if (puVar2 != (undefined1 *)0x0) goto LAB_400f9d7d;
        }
        iStack_64 = iStack_64 + iVar8;
        if (piStack_6c == (int *)0x0) {
          piVar6 = aiStack_44;
          memw();
          uStack_27 = (undefined1)param_6;
          uStack_28 = (undefined1)uVar4;
          memw();
          memw();
          piStack_2c = param_5;
          puVar2 = (undefined1 *)
                   FUN_400fb29c(*(undefined4 *)(param_1 + 0x14),param_2,0x48,param_3,&piStack_2c,8,
                                0xff);
          iVar10 = in_t0;
          if (puVar2 == (undefined1 *)0x110a) goto LAB_400f9dc5;
          if (puVar2 != (undefined1 *)0x0) goto LAB_400f9d7d;
          goto LAB_400f9ed5;
        }
        memw();
        piVar6 = piVar3;
        goto LAB_400f9d1e;
      }
      if (param_5 != (int *)0x0 || piVar1 != (int *)0x0) goto LAB_400f9d39;
LAB_400f9db2:
      if (*(int *)(iVar10 + 0xc) != -4) goto LAB_400f9de1;
      goto LAB_400f9db9;
    }
LAB_400f9d39:
    if (piVar1 != (int *)0x0) goto LAB_400f9d3c;
    puVar2 = (undefined1 *)0x1105;
LAB_400f9d7d:
    piVar6 = (int *)0xff;
    cVar11 = '\0';
    for (piVar1 = piVar5; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      memw();
      FUN_400fbaa4(piVar1[2],param_2,0x42,param_3,cVar11,0xff);
      cVar11 = cVar11 + '\x01';
    }
LAB_400f9ed5:
    while (iVar10 = in_t0, piVar5 != (int *)0x0) {
      piVar1 = (int *)piVar5[1];
      iVar10 = *piVar5;
      piVar6 = piVar1;
      if (iVar10 != 0) {
        *(int **)(iVar10 + 4) = piVar1;
        piVar6 = piVar5;
      }
      if (piVar1 != (int *)0x0) {
        *piVar1 = iVar10;
      }
      memw();
      (*(code *)&SUB_40094d80)(piVar5);
      piVar5 = piVar6;
    }
  } while( true );
}

