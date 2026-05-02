// Function : FUN_400fc6c8
// Address  : 0x400fc6c8
// Size     : 103 bytes


undefined4 FUN_400fc6c8(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_1 == (int *)0x0) {
LAB_400fc72a:
    uVar3 = 0x16;
  }
  else {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2 != (undefined4 *)0xffffffff) {
      if (puVar2 == (undefined4 *)0x0) goto LAB_400fc72a;
      iVar1 = (*(code *)&SUB_40082da0)(puVar2,0);
      if (iVar1 == 0x10) {
        return 0x10;
      }
      uVar3 = *puVar2;
      if (puVar2[1] != 1) goto LAB_400fc705;
      iVar1 = (*(code *)&SUB_4008fc8c)(uVar3);
      while (iVar1 != 1) {
        uVar3 = (*(code *)&SUB_40094c54)("pthread/pthread.c",0x254,"_unlock","orted!\n");
LAB_400fc705:
        iVar1 = (*(code *)&SUB_4008fab8)(uVar3,0,0);
      }
      (*(code *)&SUB_400902d4)(*puVar2);
      (*(code *)&SUB_40094d80)(puVar2);
    }
    uVar3 = 0;
  }
  return uVar3;
}

