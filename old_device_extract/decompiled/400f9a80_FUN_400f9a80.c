// Function : FUN_400f9a80
// Address  : 0x400f9a80
// Size     : 193 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f9a80(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iStack_48;
  undefined1 auStack_44 [2];
  byte bStack_42;
  undefined1 auStack_3c [20];
  undefined1 uStack_28;
  undefined1 uStack_27;
  int iStack_24;
  
  memw();
  iVar1 = *(int *)(param_1 + 0x10);
  memw();
  iStack_24 = _DAT_3ffc5708;
  do {
    uVar4 = 0;
    if (iVar1 == 0) {
LAB_400f9b2c:
      memw();
      memw();
      if (iStack_24 != _DAT_3ffc5708) {
        (*(code *)&SUB_40082ec4)();
      }
      return uVar4;
    }
    iStack_48 = 0;
    while( true ) {
      memw();
      iVar2 = FUN_400fb6ac(iVar1,0xff,0x48,0,&iStack_48,auStack_44,0xff,0xff);
      if (iVar2 != 0) break;
      piVar3 = (int *)(*(code *)&SUB_40094d60)(0x1c);
      if (piVar3 == (int *)0x0) {
        uVar4 = 0x101;
        goto LAB_400f9b2c;
      }
      *piVar3 = 0;
      piVar3[1] = 0;
      memw();
      (*(code *)&SUB_4008c0f8)(piVar3 + 2,auStack_3c,0x10);
      *(undefined1 *)((int)piVar3 + 0x17) = 0;
      memw();
      *(undefined1 *)(piVar3 + 6) = auStack_44[0];
      memw();
      *(undefined1 *)((int)piVar3 + 0x1a) = uStack_27;
      memw();
      *(undefined1 *)((int)piVar3 + 0x19) = uStack_28;
      memw();
      if (param_2[1] != 0) {
        *(int **)(param_2[1] + 4) = piVar3;
      }
      *piVar3 = param_2[1];
      iVar2 = *param_2;
      piVar3[1] = 0;
      param_2[1] = (int)piVar3;
      if (iVar2 == 0) {
        *param_2 = (int)piVar3;
      }
      param_2[2] = param_2[2] + 1;
      iStack_48 = (uint)bStack_42 + iStack_48;
      memw();
    }
    iVar1 = *(int *)(iVar1 + 4);
  } while( true );
}

