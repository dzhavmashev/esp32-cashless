// Function : FUN_4012c630
// Address  : 0x4012c630
// Size     : 263 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012c630(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_30 [12];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  (**(code **)(param_1[0x11] + 0x20))(param_1,auStack_30,*(byte *)(*param_1 + 4) ^ 1);
  piVar2 = (int *)FUN_4012a960(param_1,1);
  if (piVar2 == (int *)0x0) {
    if (param_1[0x20] == 0x16) goto LAB_4012c69c;
    FUN_4012a73c(param_1,2,10);
    piVar2 = (int *)&DAT_ffff8900;
  }
  do {
    while( true ) {
      param_1 = piVar2;
      FUN_4013ae54(auStack_30,0xc);
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
LAB_4012c69c:
      if (*(char *)param_1[0x1e] == '\x14') break;
LAB_4012c6c0:
      uVar4 = 0x32;
LAB_4012c6c3:
      FUN_4012a73c(param_1,2,uVar4);
      piVar2 = (int *)0xffff8180;
    }
    iVar3 = 4;
    if (*(char *)(*param_1 + 5) == '\x01') {
      iVar3 = 0xc;
    }
    if (param_1[0x2a] != iVar3 + 0xc) goto LAB_4012c6c0;
    iVar3 = FUN_401862dc((char *)param_1[0x1e] + iVar3,auStack_30,0xc);
    if (iVar3 != 0) {
      uVar4 = 0x33;
      goto LAB_4012c6c3;
    }
    param_1[0x81] = 0xc;
    memw();
    (*(code *)&SUB_4008b3d0)(param_1 + 0x85,auStack_30,0xc);
    if (*(char *)(param_1[0x11] + 2) == '\0') {
      iVar3 = param_1[1] + 1;
LAB_4012c711:
      param_1[1] = iVar3;
    }
    else {
      cVar1 = *(char *)(*param_1 + 4);
      if (cVar1 == '\0') {
        iVar3 = 10;
        goto LAB_4012c711;
      }
      if (cVar1 == '\x01') {
        iVar3 = 0xf;
        goto LAB_4012c711;
      }
    }
    piVar2 = (int *)0x0;
    if (*(char *)(*param_1 + 5) == '\x01') {
      memw();
      FUN_40129dc0(param_1);
    }
  } while( true );
}

