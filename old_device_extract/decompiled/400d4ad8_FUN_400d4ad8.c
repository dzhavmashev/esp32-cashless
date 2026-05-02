// Function : FUN_400d4ad8
// Address  : 0x400d4ad8
// Size     : 123 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d4ad8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  char ****ppppcVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  uint in_t0;
  undefined8 uVar7;
  char ***local_24 [9];
  
  uVar7 = CONCAT44(param_4,param_3);
  memw();
  puVar4 = (undefined1 *)0xa;
  memw();
  local_24[0] = (char ***)_DAT_3ffc5708;
  ppppcVar3 = local_24;
  uVar6 = 9;
  while( true ) {
    do {
      do {
        iVar2 = (int)((ulonglong)uVar7 >> 0x20);
        uVar5 = (uint)uVar7;
        cVar1 = (*(code *)&SUB_4000d280)(uVar5,iVar2,puVar4,0);
        ppppcVar3 = (char ****)((int)ppppcVar3 + -1);
        *(char *)ppppcVar3 = cVar1 + '0';
        uVar7 = (*(code *)&SUB_4000cff8)(uVar5,iVar2,puVar4,0);
      } while (iVar2 != 0);
    } while (uVar6 < uVar5);
    FUN_400d4aa0(param_1,ppppcVar3,(int)local_24 - (int)ppppcVar3);
    ppppcVar3 = (char ****)local_24[0];
    memw();
    memw();
    if ((char ****)local_24[0] == _DAT_3ffc5708) break;
    param_1 = in_t0;
    uVar7 = func_0x40082ecc();
    puVar4 = &DAT_3ffc5708;
    uVar6 = param_1;
    in_t0 = param_1;
  }
  return;
}

