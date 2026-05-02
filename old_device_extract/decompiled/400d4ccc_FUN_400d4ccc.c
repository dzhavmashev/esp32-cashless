// Function : FUN_400d4ccc
// Address  : 0x400d4ccc
// Size     : 221 bytes


undefined4 FUN_400d4ccc(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  byte *pbVar6;
  char cVar7;
  undefined2 auStack_28 [2];
  undefined4 uStack_24;
  
  uStack_24 = 0;
  auStack_28[0] = 0;
  iVar1 = FUN_40183ca8(param_1);
  *(undefined1 *)((int)param_1 + 0x1d) = 0;
LAB_400d4ce5:
  do {
    iVar2 = FUN_40183ca8(param_1);
    *(undefined1 *)((int)param_1 + 0x1d) = 0;
    if (iVar1 == iVar2) {
      uVar5 = 4;
      if (*(char *)(*param_1 + 0x10) == '\0') {
        uVar5 = 0;
      }
      return uVar5;
    }
    if (iVar2 == 0) {
      return 2;
    }
    if (iVar2 == 0x5c) {
      uVar3 = FUN_40183ca8(param_1,0x5c);
      if (uVar3 == 0) {
        return 2;
      }
      pbVar6 = (byte *)0x3f401ab8;
      if (uVar3 == 0x75) {
        *(undefined1 *)((int)param_1 + 0x1d) = 0;
        cVar7 = '\x04';
        uVar3 = 0;
        do {
          uVar4 = FUN_40183ca8(param_1);
          if (uVar4 == 0) {
            return 2;
          }
          if (uVar4 < 0x41) {
            uVar4 = uVar4 - 0x30;
          }
          else {
            uVar4 = (uVar4 & 0xffffffdf) - 0x37;
          }
          if (0xf < (uVar4 & 0xff)) {
            return 3;
          }
          cVar7 = cVar7 + -1;
          *(undefined1 *)((int)param_1 + 0x1d) = 0;
          uVar3 = (uVar3 & 0xfff) << 4 | uVar4 & 0xff;
        } while (cVar7 != '\0');
        iVar2 = FUN_400d4228(auStack_28,uVar3);
        if (iVar2 != 0) {
          FUN_400d4b54(uStack_24,param_1);
        }
        goto LAB_400d4ce5;
      }
      while( true ) {
        if (*pbVar6 == 0) {
          return 3;
        }
        if (uVar3 == *pbVar6) break;
        pbVar6 = pbVar6 + 2;
      }
      if (pbVar6[1] == 0) {
        return 3;
      }
      *(undefined1 *)((int)param_1 + 0x1d) = 0;
    }
    (*(code *)&LAB_40183b4f_1)(param_1);
  } while( true );
}

