// Function : FUN_400facfc
// Address  : 0x400facfc
// Size     : 151 bytes


int FUN_400facfc(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 auStack_21 [33];
  
  iVar1 = 0x102;
  if ((param_5 != (undefined4 *)0x0) && (iVar1 = 0x1101, *(int *)(param_1 + 0x18) != 0)) {
    memw();
    iVar2 = FUN_400facd8(param_1,param_2);
    iVar1 = 0x110f;
    if ((iVar2 != 0) && (iVar1 = FUN_400fa77c(iVar2,param_3,param_4 == 1,auStack_21), iVar1 == 0)) {
      puVar3 = (undefined4 *)(*(code *)&SUB_40094d60)(0x14);
      if (puVar3 == (undefined4 *)0x0) {
        iVar1 = 0x101;
      }
      else {
        puVar3[3] = iVar2;
        iVar2 = *(int *)(param_1 + 8);
        puVar3[1] = 0;
        puVar3[2] = 0;
        *puVar3 = &DAT_3f40d36c;
        *(undefined1 *)(puVar3 + 4) = auStack_21[0];
        *(bool *)((int)puVar3 + 0x11) = param_4 == 0;
        *(undefined1 *)((int)puVar3 + 0x12) = 1;
        memw();
        if (iVar2 != 0) {
          *(undefined4 **)(iVar2 + 8) = puVar3;
        }
        puVar3[2] = 0;
        iVar4 = *(int *)(param_1 + 4);
        puVar3[1] = iVar2;
        *(undefined4 **)(param_1 + 8) = puVar3;
        if (iVar4 == 0) {
          *(undefined4 **)(param_1 + 4) = puVar3;
        }
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        *param_5 = puVar3;
      }
    }
  }
  memw();
  return iVar1;
}

