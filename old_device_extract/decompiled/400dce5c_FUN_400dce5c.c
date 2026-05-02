// Function : FUN_400dce5c
// Address  : 0x400dce5c
// Size     : 719 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400dce5c(int param_1)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  undefined1 uVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  undefined2 uStack_3a;
  int iStack_38;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (*(char *)(param_1 + 0x50) != '\0') {
    memw();
    if (*(char *)(param_1 + 0x6f) == '\0') goto LAB_400dcf11;
    memw();
    *(undefined1 *)(param_1 + 0x6f) = 0;
    FUN_400f0780(0x3ffc5490,"_active");
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar6 = *(int *)(param_1 + 0x40);
      piVar4 = *(int **)(param_1 + 0x3c);
      while ((int *)iVar6 != piVar4) {
        piVar7 = piVar4;
        if ((*(byte *)((int)piVar4 + 0xf) & 0x80) == 0) {
          piVar7 = (int *)*piVar4;
        }
        (*(code *)&SUB_40002c34)(piVar4[4]);
        FUN_400f06a4(0x3ffc5490,"iveries",piVar7);
        iStack_38 = piVar4[4];
        uStack_3a = 0;
        if (*(int *)(param_1 + 0xc) == 0) {
          FUN_40170584();
        }
        (**(code **)(param_1 + 0x10))(param_1 + 4,piVar4,&iStack_38,&uStack_3a);
        piVar4 = piVar4 + 5;
      }
    }
    FUN_400dc5a0(param_1);
  }
LAB_400dcef8:
  while( true ) {
    while( true ) {
      do {
        param_1 = _DAT_3ffc5708;
        memw();
        memw();
        if (iStack_24 == _DAT_3ffc5708) {
          return;
        }
        func_0x40082ecc();
LAB_400dcf11:
        if (*(int *)(param_1 + 0x54) != 0) {
          FUN_400dbfa8();
        }
      } while (((*(int *)(param_1 + 0x54) == 0) || (*(char *)(*(int *)(param_1 + 0x54) + 5) == '\0')
               ) || (*(char *)(param_1 + 0x66) != '\0'));
      uVar3 = FUN_400f1a9c();
      cVar1 = *(char *)(*(int *)(param_1 + 0x54) + 4);
      if (*(uint *)(param_1 + 0x5c) <= uVar3) break;
      if (((*(char *)(param_1 + 0x70) != '\0') && (*(char *)(param_1 + 0x30) != '\0')) &&
         (cVar1 != '\0')) {
        FUN_400f0780(0x3ffc5490,"t=%.2f\n");
        FUN_400dc3c8(param_1);
      }
    }
    cVar2 = *(char *)(param_1 + 0x5a);
    if (cVar2 != '\x01') break;
    if (*(char *)(param_1 + 0x30) == cVar1) {
      *(undefined1 *)(param_1 + 0x5a) = 0;
      *(undefined4 *)(param_1 + 0x60) = 0;
    }
    else if ((uint)*(ushort *)(param_1 + 0x58) <= uVar3 - *(int *)(param_1 + 0x60)) {
      if ((*(char *)(param_1 + 0x70) != '\x01') && (*(char *)(param_1 + 0x30) != '\0')) {
        FUN_400dc39c(param_1);
      }
      if (*(byte *)(param_1 + 100) < *(byte *)(param_1 + 0x6e)) {
        *(byte *)(param_1 + 100) = *(byte *)(param_1 + 100) + 1;
        *(char *)(param_1 + 0x65) = cVar1;
        FUN_400f06a4(0x3ffc5490,"_failed");
        FUN_400f0be8(auStack_34,"rPaused");
        FUN_400dcc90(param_1,auStack_34);
        FUN_400f0a50(auStack_34);
        FUN_400f0be8(auStack_34," %d/%d\n");
        FUN_400dc0a0(param_1,auStack_34);
LAB_400dd060:
        FUN_400f0a50(auStack_34);
        uVar5 = 2;
        goto LAB_400dcfa7;
      }
      *(undefined1 *)(param_1 + 0x66) = 1;
      FUN_400f0780(0x3ffc5490,"g timer");
      FUN_400f0be8(auStack_34,"reached");
      FUN_400dcc90(param_1,auStack_34);
LAB_400dd0d8:
      FUN_400f0a50(auStack_34);
    }
  }
  if (cVar2 == '\0') goto LAB_400dcf9c;
  if (cVar2 == '\x02') {
    pcVar8 = "rcement";
    if (*(char *)(param_1 + 0x30) != cVar1) {
      if ((uint)*(ushort *)(param_1 + 0x6a) <= uVar3 - *(int *)(param_1 + 0x60)) {
        FUN_400f0780(0x3ffc5490,"eceived");
        uVar5 = 3;
        goto LAB_400dcfa7;
      }
      goto LAB_400dcef8;
    }
  }
  else {
    if (cVar2 != '\x03') goto LAB_400dcef8;
    if (*(char *)(param_1 + 0x30) != cVar1) {
      if ((uint)*(ushort *)(param_1 + 0x6c) <= uVar3 - *(int *)(param_1 + 0x60)) {
        if (*(byte *)(param_1 + 100) < *(byte *)(param_1 + 0x6e)) {
          *(byte *)(param_1 + 100) = *(byte *)(param_1 + 100) + 1;
          *(char *)(param_1 + 0x65) = cVar1;
          FUN_400f06a4(0x3ffc5490,"ooldown");
          FUN_400f0be8(auStack_34,"rPaused");
          FUN_400dcc90(param_1,auStack_34);
          FUN_400f0a50(auStack_34);
          FUN_400f0be8(auStack_34," %d/%d\n");
          FUN_400dc0a0(param_1,auStack_34);
          goto LAB_400dd060;
        }
        *(undefined1 *)(param_1 + 0x66) = 1;
        FUN_400f0780(0x3ffc5490,"ooldown");
        FUN_400f0be8(auStack_34,"reached");
        FUN_400dcc90(param_1,auStack_34);
        goto LAB_400dd0d8;
      }
      goto LAB_400dcef8;
    }
    pcVar8 = "ooldown";
  }
  FUN_400f0780(0x3ffc5490,pcVar8);
  FUN_400dc564(param_1);
  goto LAB_400dcef8;
LAB_400dcf9c:
  if (*(char *)(param_1 + 0x30) != cVar1) {
    uVar5 = 1;
LAB_400dcfa7:
    *(undefined1 *)(param_1 + 0x5a) = uVar5;
    *(uint *)(param_1 + 0x60) = uVar3;
  }
  goto LAB_400dcef8;
}

