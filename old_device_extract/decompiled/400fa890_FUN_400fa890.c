// Function : FUN_400fa890
// Address  : 0x400fa890
// Size     : 395 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fa890(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piStack_50;
  int *piStack_4c;
  int *piStack_48;
  undefined1 uStack_44;
  char cStack_43;
  byte bStack_42;
  undefined1 auStack_3c [16];
  undefined1 uStack_2c;
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_400fc1d4(param_1 + 0x10,*(undefined4 *)(param_1 + 8),param_2,param_3);
  if (iVar1 == 0) goto LAB_400fa8d7;
  *(undefined4 *)(param_1 + 100) = 0;
LAB_400fa8bd:
  do {
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    memw();
    (*(code *)&SUB_40082ec4)();
LAB_400fa8d7:
    FUN_400fa6e4(param_1 + 0x38);
    *(int *)(param_1 + 0x44) = iVar1;
    for (piVar3 = *(int **)(param_1 + 0x10); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[1]) {
      piStack_50 = (int *)0x0;
      while( true ) {
        memw();
        iVar1 = FUN_400fb6ac(piVar3,0,1,0,&piStack_50,&uStack_44,0xff,0xff);
        if (iVar1 != 0) break;
        puVar2 = (undefined4 *)(*(code *)&SUB_40094d60)(0x1c);
        if (puVar2 == (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 100) = 0;
          memw();
          goto LAB_400fa9c9;
        }
        *puVar2 = 0;
        puVar2[1] = 0;
        memw();
        (*(code *)&SUB_4008c0f8)(puVar2 + 2,auStack_3c,0x10);
        *(undefined1 *)((int)puVar2 + 0x17) = 0;
        memw();
        if (cStack_43 != '\x01') {
          iVar1 = -1;
          goto LAB_400fa8bd;
        }
        *(undefined1 *)(puVar2 + 6) = uStack_2c;
        memw();
        memw();
        FUN_40184910(param_1 + 0x38,puVar2);
        iVar1 = param_1 + (uint)(*(byte *)(puVar2 + 6) >> 5) * 4;
        *(uint *)(iVar1 + 0x44) =
             *(uint *)(iVar1 + 0x44) | 1 << 0x20 - (0x20 - (*(byte *)(puVar2 + 6) & 0x1f));
        piStack_50 = (int *)((uint)bStack_42 + (int)piStack_50);
        memw();
      }
    }
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xfffffffe | 1;
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) & 0x7fffffff | 0x80000000;
    *(undefined4 *)(param_1 + 100) = 1;
    memw();
    piStack_50 = piVar3;
    piStack_4c = piVar3;
    piStack_48 = piVar3;
    iVar1 = FUN_400f9a80(param_1,&piStack_50);
    if (iVar1 == 0) {
      FUN_400f9b44(param_1,&piStack_50);
      while (iVar1 = 0, piStack_50 != (int *)0x0) {
        piVar3 = (int *)*piStack_50;
        piVar4 = (int *)piStack_50[1];
        if (piVar3 == (int *)0x0) {
          memw();
          piStack_50 = piVar4;
        }
        else {
          piVar3[1] = (int)piVar4;
        }
        if (piVar4 == (int *)0x0) {
          memw();
          piStack_4c = piVar3;
        }
        else {
          *piVar4 = (int)piVar3;
        }
        piStack_48 = (int *)((int)piStack_48 + -1);
        memw();
        (*(code *)&SUB_40094d80)();
      }
    }
    else {
      *(undefined4 *)(param_1 + 100) = 0;
LAB_400fa9c9:
      iVar1 = 0x101;
      memw();
    }
  } while( true );
}

