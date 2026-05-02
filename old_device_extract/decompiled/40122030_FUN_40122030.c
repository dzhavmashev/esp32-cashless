// Function : FUN_40122030
// Address  : 0x40122030
// Size     : 317 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40122030(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int in_a6;
  int in_a7;
  undefined4 uVar7;
  undefined4 uStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [36];
  undefined4 uStack_28;
  undefined1 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  uStack_7c = 0;
  memw();
  (*(code *)&SUB_4008b530)(auStack_50,0,0x2c);
  iStack_78 = 0;
  memw();
  puVar1 = (undefined1 *)FUN_40185694();
  uStack_74 = 0;
  memw();
  (*(code *)&SUB_4008b530)(auStack_70,0,0x20);
  if ((undefined1 *)0x20 < puVar1) {
    (*(code *)&SUB_40094c54)("ump/src/core_dump_flash.c",0x178,"hecksum","am_info");
  }
  iVar2 = FUN_40121c5c(&uStack_7c,&iStack_78);
  if (iVar2 != 0) goto LAB_40122104;
  puVar5 = (undefined1 *)(iStack_78 - (int)puVar1);
  FUN_40123210(&uStack_28);
  puVar6 = (undefined1 *)0x20;
  in_a6 = 0;
  do {
    if (puVar5 == (undefined1 *)0x0) {
      FUN_40123270(uStack_28,&uStack_74);
      iVar2 = FUN_400f90c0(uStack_7c,iStack_78 - (int)puVar1,auStack_70,puVar1);
      if (iVar2 == 0) {
        iVar4 = (*(code *)&SUB_4008b33c)(uStack_74,auStack_70,puVar1);
        iVar2 = 0;
        if (iVar4 != 0) {
          uVar3 = (*(code *)&SUB_40094ae8)();
          (*(code *)&SUB_40007d54)(0x3ffc0b09,uVar3,0x3ffc0d6d);
          FUN_401232a4("flash.c",uStack_74);
          FUN_401232a4("hecksum",auStack_70);
          iVar2 = 0x109;
        }
      }
      else {
        uVar3 = (*(code *)&SUB_40094ae8)();
        uVar7 = 0x3ffc0b32;
LAB_401220fe:
        (*(code *)&SUB_40007d54)(uVar7,uVar3,0x3ffc0d6d,iVar2);
      }
LAB_40122104:
      puVar1 = puStack_24;
      puVar5 = _DAT_3ffc5708;
      memw();
      memw();
      if (puStack_24 == _DAT_3ffc5708) {
        return iVar2;
      }
      (*(code *)&SUB_40082ec4)();
      puVar6 = &DAT_3ffc5708;
    }
    else {
      in_a7 = (uint)(puVar5 < puVar6) * (int)puVar5 + (uint)(puVar5 >= puVar6) * (int)puVar6;
      iVar2 = FUN_400f90c0(uStack_7c,in_a6,auStack_4c,in_a7);
      if (iVar2 != 0) {
        uVar3 = (*(code *)&SUB_40094ae8)();
        uVar7 = 0x3ffc0b6b;
        goto LAB_401220fe;
      }
    }
    FUN_40123228(uStack_28,auStack_4c,in_a7);
    in_a6 = in_a6 + in_a7;
    puVar5 = puVar5 + -in_a7;
  } while( true );
}

