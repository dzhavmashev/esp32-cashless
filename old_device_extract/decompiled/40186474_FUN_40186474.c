// Function : FUN_40186474
// Address  : 0x40186474
// Size     : 79 bytes


void FUN_40186474(undefined4 *param_1,char param_2,uint param_3)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar1 = (uint *)param_1[2];
  *puVar1 = *puVar1 ^ 0xffffffff;
  uVar5 = 0;
  puVar4 = puVar1;
  do {
    uVar5 = uVar5 + 1;
    uVar3 = *puVar4;
    *puVar4 = uVar3 + 1;
    puVar4 = puVar4 + 1;
    if (param_3 >> 5 < uVar5) break;
  } while (uVar3 + 1 == 0);
  piVar2 = (int *)((int)puVar1 + (param_3 >> 3));
  *param_1 = 0xffffffff;
  *piVar2 = *piVar2 - (int)param_2;
  memw();
  return;
}

