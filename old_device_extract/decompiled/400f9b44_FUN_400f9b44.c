// Function : FUN_400f9b44
// Address  : 0x400f9b44
// Size     : 317 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f9b44(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iStack_e8;
  undefined1 uStack_e4;
  undefined1 uStack_e3;
  byte bStack_e2;
  undefined1 uStack_e1;
  undefined1 auStack_dc [24];
  undefined1 auStack_c4 [32];
  undefined1 auStack_a4 [32];
  undefined1 auStack_84 [32];
  undefined1 auStack_64 [32];
  char acStack_44 [3];
  byte bStack_41;
  undefined1 auStack_3c [24];
  int iStack_24;
  
  memw();
  iVar2 = *(int *)(param_1 + 0x10);
  memw();
  iStack_24 = _DAT_3ffc5708;
  do {
    if (iVar2 == 0) {
      memw();
      memw();
      if (iStack_24 != _DAT_3ffc5708) {
        (*(code *)&SUB_40082ec4)();
      }
      return;
    }
    iStack_e8 = 0;
    while( true ) {
      memw();
      iVar3 = FUN_400fb6ac(iVar2,0xff,0x42,0,&iStack_e8,&uStack_e4,0xff,0xff);
      if (iVar3 != 0) break;
      iVar3 = *param_2;
      (*(code *)&SUB_4008b3d0)(auStack_c4,&uStack_e4,0x20);
      uVar4 = (*(code *)&SUB_4008b3d0)(auStack_a4,auStack_c4,0x20);
      (*(code *)&SUB_4008b3d0)(auStack_64,uVar4,0x20);
      (*(code *)&SUB_4008b3d0)(acStack_44,auStack_64,0x20);
      (*(code *)&SUB_4008b3d0)(auStack_84,acStack_44,0x20);
      (*(code *)&SUB_4008b3d0)(auStack_64,auStack_84,0x20);
      (*(code *)&SUB_4008b3d0)(acStack_44,auStack_64,0x20);
      cVar1 = acStack_44[0];
      uVar6 = (uint)bStack_41;
      for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
        memw();
        iVar5 = (*(code *)&SUB_4008c080)(auStack_3c,iVar3 + 8,0xf);
        if ((((iVar5 == 0) && (*(char *)(iVar3 + 0x18) == cVar1)) &&
            (*(byte *)(iVar3 + 0x1a) <= uVar6)) &&
           (uVar6 < (uint)*(byte *)(iVar3 + 0x19) + (uint)*(byte *)(iVar3 + 0x1a)))
        goto LAB_400f9c5a;
      }
      FUN_400fbaa4(iVar2,uStack_e4,uStack_e3,auStack_dc,uStack_e1,0xff);
LAB_400f9c5a:
      iStack_e8 = (uint)bStack_e2 + iStack_e8;
      memw();
    }
    iVar2 = *(int *)(iVar2 + 4);
  } while( true );
}

