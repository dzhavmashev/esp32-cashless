// Function : FUN_40106450
// Address  : 0x40106450
// Size     : 85 bytes


/* WARNING: Removing unreachable block (ram,0x40106487) */

void FUN_40106450(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  (*(code *)&SUB_40085bfc)();
  uVar2 = (*(code *)&SUB_4000c988)();
  (*(code *)&SUB_40002954)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x412e8480);
  lVar3 = (*(code *)&SUB_40002ac4)();
  while ((puVar1 = (undefined4 *)*param_1, puVar1 != (undefined4 *)0x0 &&
         ((int)puVar1[0x16] <= lVar3))) {
    *param_1 = *puVar1;
    memw();
    FUN_401063cc(param_1,puVar1,2);
  }
  FUN_401063f0(param_1);
  return;
}

