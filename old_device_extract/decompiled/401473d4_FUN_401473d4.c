// Function : FUN_401473d4
// Address  : 0x401473d4
// Size     : 282 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401473d4(int *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar1 = 0x102;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    iVar2 = FUN_401460c8();
    iVar1 = 0x3001;
    if (iVar2 != 0) {
      if (param_2 == '\0') {
        iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x178))(0xc);
        if (iVar1 != 0) {
          (*(code *)&SUB_4008b3d0)(iVar1,param_1,0xc);
          if ((param_1[2] != 0) && (param_1[1] != 0)) {
            iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x178))();
            *(int *)(iVar1 + 4) = iVar2;
            if (iVar2 == 0) {
              memw();
              (*(code *)&SUB_40094d80)(iVar1);
              return 0x101;
            }
            (*(code *)&SUB_4008b3d0)(iVar2,param_1[1],param_1[2]);
          }
          puVar3 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
          if (puVar3 == (undefined1 *)0x0) {
            iVar2 = 0x101;
          }
          else {
            *puVar3 = 0x31;
            memw();
            *(undefined1 **)(puVar3 + 4) = &LAB_40150194;
            puVar3[8] = 2;
            puVar3[9] = 0;
            puVar3[10] = 0;
            memw();
            *(int *)(puVar3 + 0xc) = iVar1;
            *(undefined4 *)(puVar3 + 0x14) = 0;
            memw();
            iVar2 = FUN_40150444();
            if (iVar2 == 0) {
              return 0;
            }
          }
          FUN_40147fe4(1,2,1,&DAT_3f400120);
          if ((param_1[2] != 0) && (param_1[1] != 0)) {
            (*(code *)&SUB_40094d80)(*(undefined4 *)(iVar1 + 4));
          }
          (*(code *)&SUB_40094d80)(iVar1);
          return iVar2;
        }
      }
      else {
        puVar3 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
        if (puVar3 != (undefined1 *)0x0) {
          *puVar3 = 0x31;
          memw();
          *(undefined1 **)(puVar3 + 4) = &LAB_40150194;
          puVar3[8] = 1;
          puVar3[9] = 0;
          puVar3[10] = 0;
          memw();
          *(int **)(puVar3 + 0xc) = param_1;
          *(undefined4 *)(puVar3 + 0x14) = 0;
          memw();
          iVar1 = FUN_40150444();
          return iVar1;
        }
      }
      return 0x101;
    }
  }
  return iVar1;
}

